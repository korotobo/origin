#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Report {
public:
    std::string date;
    std::string title;
    std::string content;

    Report(const std::string& date, const std::string& title, const std::string& content)
        : date(date), title(title), content(content) {}
};

class Printer {
public:
    virtual ~Printer() = default;
    virtual std::string wrap_element(const std::string& data) const = 0;
    virtual std::string wrap_report(const std::vector<std::string>& elements) const = 0;
};

class PrinterHTML : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return "<p>" + data + "</p>";
    }

    std::string wrap_report(const std::vector<std::string>& elements) const override {
        std::string report = "<html><body>";
        for (const auto& element : elements) {
            report += element + "\n";
        }
        report += "</body></html>";
        return report;
    }
};

class PrinterJSON : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return "{ \"item\": \"" + data + "\" }";
    }

    std::string wrap_report(const std::vector<std::string>& elements) const override {
        std::string report = "[";
        for (size_t i = 0; i < elements.size(); ++i) {
            report += elements[i];
            if (i < elements.size() - 1) {
                report += ",";
            }
        }
        report += "]";
        return report;
    }
};

class PrinterText : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return data;
    }

    std::string wrap_report(const std::vector<std::string>& elements) const override {
        std::string report;
        for (const auto& element : elements) {
            report += element + "\n";
        }
        return report;
    }
};

class ReportFormatter {
public:
    void saveReportToFile(std::ofstream &file, const Report& report, std::shared_ptr<Printer> printer) {
        std::vector<std::string> elements;
        elements.push_back(printer->wrap_element(report.date));
        elements.push_back(printer->wrap_element(report.title));
        elements.push_back(printer->wrap_element(report.content));
        file << printer->wrap_report(elements);
    }
};

void saveReport(const std::string& filename, const Report& report, std::shared_ptr<Printer> printer) {
    std::ofstream file(filename);
    if (file.is_open()) {
        ReportFormatter formatter;
        formatter.saveReportToFile(file, report, printer);
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл " << filename << " для записи." << std::endl;
    }
}


int main() {
    Report report("2023-10-01", "Отчет о продажах", "Содержание отчета...");

    saveReport("output.html", report, std::make_shared<PrinterHTML>());
    saveReport("output.json", report, std::make_shared<PrinterJSON>());
    saveReport("output.txt", report, std::make_shared<PrinterText>());

    return 0;
}
