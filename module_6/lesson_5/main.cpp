#include <iostream>
#include <pqxx/pqxx>
#include <string>

class ClientManager {
public:
    ClientManager(const std::string& connection_string) : conn(connection_string) {
        createTable();
        prepareStatements();
    }

    void createTable() {
        pqxx::work txn(conn);
        txn.exec("CREATE TABLE IF NOT EXISTS clients ("
                  "id SERIAL PRIMARY KEY, "
                  "first_name VARCHAR(100), "
                  "last_name VARCHAR(100), "
                  "email VARCHAR(100) UNIQUE, "
                  "phone_number VARCHAR(15));");
        txn.commit();
    }

    void prepareStatements() {
        conn.prepare("insert_client", "INSERT INTO clients (first_name, last_name, email, phone_number) VALUES ($1, $2, $3, $4);");
        conn.prepare("update_client", "UPDATE clients SET first_name = $1, last_name = $2, email = $3, phone_number = $4 WHERE id = $5;");
        conn.prepare("delete_client", "DELETE FROM clients WHERE id = $1;");
        conn.prepare("find_client", "SELECT * FROM clients WHERE first_name ILIKE $1 OR last_name ILIKE $1 OR email ILIKE $1;");
    }

    void addClient(const std::string& first_name, const std::string& last_name, const std::string& email, const std::string& phone_number) {
        pqxx::work txn(conn);
        txn.prepared("insert_client")(first_name)(last_name)(email)(phone_number).exec();
        txn.commit();
    }

    void updateClient(int client_id, const std::string& first_name, const std::string& last_name, const std::string& email, const std::string& phone_number) {
        pqxx::work txn(conn);
        txn.prepared("update_client")(first_name)(last_name)(email)(phone_number)(client_id).exec();
        txn.commit();
    }

    void deleteClient(int client_id) {
        pqxx::work txn(conn);
        txn.prepared("delete_client")(client_id).exec();
        txn.commit();
    }

    void findClient(const std::string& search_term) {
        pqxx::work txn(conn);
        pqxx::result r = txn.prepared("find_client")("%" + search_term + "%").exec();
        for (const auto& row : r) {
            std::cout << "ID: " << row[0].as<int>() << ", Name: " << row[1].as<std::string>() << " " << row[2].as<std::string>() << ", Email: " << row[3].as<std::string>() << ", Phone: " << row[4].as<std::string>() << std::endl;
        }
    }

private:
    pqxx::connection conn;
};

int main() {
    try {
        ClientManager cm(
                    "host=localhost "
                    "port=5432 "
                    "dbname=lesson5 "
                    "user=postgres "
                    "password=forpsql8914");

        cm.addClient("Иван", "Иванов", "ivanivanov@mail.ru", "+71234567890");
        cm.findClient("Иван");
        cm.updateClient(1, "Петр", "Петров", "petrpetrov@mail.ru", "+70987654321");
        cm.deleteClient(1);
        cm.addClient("Сергей", "Сергеев", "sergsergeev@mail.ru", "+79990001234");
        cm.findClient("ivanivanov@mail.ru");
        cm.findClient("Сергеев");

    } catch (const pqxx::failure& e) {
        std::cerr << "ErrorDB: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
