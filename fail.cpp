
#include <iostream>
#include <vector>
#include <string>

struct Client {
    std::string firstName;
    std::string lastName;
    std::string email;
    std::vector<std::string> phoneNumbers;
};

class ClientManager {
private:
    std::vector<Client> clients;

public:
    void addClient(const std::string& firstName, const std::string& lastName, const std::string& email) {
        Client newClient;
        newClient.firstName = firstName;
        newClient.lastName = lastName;
        newClient.email = email;
        clients.push_back(newClient);
    }

    void addPhoneNumber(int clientIndex, const std::string& phoneNumber) {
        if (clientIndex >= 0 && clientIndex < clients.size()) {
            clients[clientIndex].phoneNumbers.push_back(phoneNumber);
        }
    }

    void updateClient(int clientIndex, const std::string& firstName, const std::string& lastName, const std::string& email) {
        if (clientIndex >= 0 && clientIndex < clients.size()) {
            clients[clientIndex].firstName = firstName;
            clients[clientIndex].lastName = lastName;
            clients[clientIndex].email = email;
        }
    }

    void removePhoneNumber(int clientIndex, int phoneNumberIndex) {
        if (clientIndex >= 0 && clientIndex < clients.size()) {
            if (phoneNumberIndex >= 0 && phoneNumberIndex < clients[clientIndex].phoneNumbers.size()) {
                clients[clientIndex].phoneNumbers.erase(clients[clientIndex].phoneNumbers.begin() + phoneNumberIndex);
            }
        }
    }

    void removeClient(int clientIndex) {
        if (clientIndex >= 0 && clientIndex < clients.size()) {
            clients.erase(clients.begin() + clientIndex);
        }
    }

    std::vector<Client> searchClients(const std::string& searchTerm) {
        std::vector<Client> searchResults;
        for (const auto& client : clients) {
            if (client.firstName == searchTerm || client.lastName == searchTerm || client.email == searchTerm) {
                searchResults.push_back(client);
            } else {
                for (const auto& phoneNumber : client.phoneNumbers) {
                    if (phoneNumber == searchTerm) {
                        searchResults.push_back(client);
                        break;
                    }
                }
            }
        }
        return searchResults;
    }
};

int main() {
    ClientManager manager;

    // Пример использования методов класса
    manager.addClient("John", "Doe", "john.doe@example.com");
    manager.addPhoneNumber(0, "123456789");
    manager.addPhoneNumber(0, "987654321");

    manager.updateClient(0, "John", "Smith", "john.smith@example.com");

    manager.removePhoneNumber(0, 1);

    std::vector<Client> searchResults = manager.searchClients("John");
    for (const auto& client : searchResults) {
        std::cout << "Name: " << client.firstName << " " << client.lastName << std::endl;
        std::cout << "Email: " << client.email << std::endl;
        std::cout << "Phone Numbers: ";
        for (const auto& phoneNumber : client.phoneNumbers) {
            std::cout << phoneNumber << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
