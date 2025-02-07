#include <iostream>
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder() : from_(""), where_conditions_() {}

    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        for (const auto& column : columns) {
            columns_.push_back(column);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        from_ = table;
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) {
        where_conditions_.push_back(column + "=" + value);
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& pair : kv) {
            where_conditions_.push_back(pair.first + "=" + pair.second);
        }
        return *this;
    }

    std::string BuildQuery() const {
        std::string query = "SELECT ";
        if (columns_.empty()) {
            query += "*";
        } else {
            for (size_t i = 0; i < columns_.size(); ++i) {
                query += columns_[i];
                if (i < columns_.size() - 1) {
                    query += ", ";
                }
            }
        }
        query += " FROM " + from_;
        if (!where_conditions_.empty()) {
            query += " WHERE ";
            for (size_t i = 0; i < where_conditions_.size(); ++i) {
                query += where_conditions_[i];
                if (i < where_conditions_.size() - 1) {
                    query += " AND ";
                }
            }
        }
        query += ";";
        return query;
    }

private:
    std::vector<std::string> columns_;
    std::string from_;
    std::vector<std::string> where_conditions_;
};

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({"name", "phone"});
    query_builder.AddFrom("students");

    std::map<std::string, std::string> conditions = {{"id", "42"}, {"name", "John"}};
    query_builder.AddWhere(conditions);

    std::string query = query_builder.BuildQuery();
    std::cout << query << std::endl;

    return 0;
}
