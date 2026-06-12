/*
 * MiniStocks created by Daniel Kostuj
 *
 * This file contains all definitions for the TickerInfoDownloader class.
 * The TickerInfoDownloader class downloads the newest stock price info for a single ticker.
 *
 * Use of this source code is governed by the license that can be
 * found in the LICENSE file.
 */
#include "../file/File.h"
#include "TickerInfoDownloader.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#ifdef HAS_CURL
#include "curl/curl.h"
#else
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QNetworkRequest>
#include <QObject>
#endif

TickerInfoDownloader::TickerInfoDownloader(const QString &ticker) : tickerSymbol(ticker)
{
}

void TickerInfoDownloader::downloadData(const QString &url, const QString &filepath) {
    File::makeSaveDir();
#ifdef HAS_CURL
    if ((curl = curl_easy_init())) {
        fp = fopen(filepath.toLatin1().data(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.toLatin1().data());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_callback());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
        return;
    }
    throw;
#else
    QNetworkAccessManager manager;
    QNetworkReply *reply;
    QEventLoop loop;
    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "Mozilla/5.0");
    reply = manager.get(request);
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.write(reply->readAll());
    file.close();
    reply->deleteLater();
#endif
}

QString TickerInfoDownloader::convertSymbol(const QString &symbol) {
    QString s = symbol;
    if (s.endsWith(".US")) s.chop(3);
    if (s == "CL.F")  return "CL=F";
    if (s == "GC.F")  return "GC=F";
    if (s == "^SPX")  return "^GSPC";
    if (s == "EURUSD") return "EURUSD=X";
    return s;
}

std::vector<QString> TickerInfoDownloader::parseYahooJSON(const QByteArray &data) {
    std::vector<QString> result;
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (doc.isNull()) return result;

    QJsonObject root = doc.object();
    QJsonObject chart = root["chart"].toObject();
    QJsonArray results = chart["result"].toArray();

    if (results.isEmpty()) return result;

    QJsonObject meta = results[0].toObject()["meta"].toObject();

    double price      = meta["regularMarketPrice"].toDouble();
    double open       = meta["regularMarketOpen"].toDouble();
    QString symbol    = meta["symbol"].toString();

    if (price == 0.0) return result;

    result.emplace_back(symbol);
    result.emplace_back(QString::number(open, 'f', 4));
    result.emplace_back(QString::number(meta["regularMarketDayHigh"].toDouble(), 'f', 4));
    result.emplace_back(QString::number(meta["regularMarketDayLow"].toDouble(), 'f', 4));
    result.emplace_back(QString::number(price, 'f', 4));
    result.emplace_back(QString::number(meta["regularMarketVolume"].toDouble(), 'f', 0));
    result.emplace_back("");
    result.emplace_back(QString::number(meta["previousClose"].toDouble(), 'f', 4));
    result.emplace_back(QString::number(price - open, 'f', 4));
    result.emplace_back(QString::number((price - open) / open * 100.0, 'f', 4));

    return result;
}

void TickerInfoDownloader::downloadAndParseCSVFile() {
    if (!this->stockData.empty() && lastFetchTime.elapsed() < 300000)
        return;

    auto fileName = "/quotes_" + tickerSymbol + ".json";
    auto fileLocation = File::getFileInSaveDir(fileName);

    QString symbol = convertSymbol(tickerSymbol);
    QString url = "https://query1.finance.yahoo.com/v8/finance/chart/" + symbol +
                  "?interval=1d&range=1d";

    try {
        downloadData(url, fileLocation);
    } catch (...) {
        qDebug() << "Cannot download data for" << tickerSymbol;
        return;
    }

    QFile file(fileLocation);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file for" << tickerSymbol;
        return;
    }
    QByteArray content = file.readAll();
    file.close();
    QFile::remove(fileLocation);

    this->stockData = parseYahooJSON(content);

    if (this->stockData.empty())
        qDebug() << "No data for" << tickerSymbol;
    else
        lastFetchTime.restart();
}

std::vector<QString> TickerInfoDownloader::getData() {
    downloadAndParseCSVFile();
    return this->stockData;
}
