#include <iostream>
#include <vector>
#include <string>

class Passport {
public:
    Passport(const std::string& full_name, const std::string& passport_number, const std::string& date_of_birth, const std::string& nationality)
        : full_name(full_name), passport_number(passport_number), date_of_birth(date_of_birth), nationality(nationality) {}

    void displayInfo() const {
        std::cout << "Full Name: " << full_name << std::endl;
        std::cout << "Passport Number: " << passport_number << std::endl;
        std::cout << "Date of Birth: " << date_of_birth << std::endl;
        std::cout << "Nationality: " << nationality << std::endl;
    }

private:
    std::string full_name;
    std::string passport_number;
    std::string date_of_birth;
    std::string nationality;
};

class ForeignPassport : public Passport {
public:
    ForeignPassport(const std::string& full_name, const std::string& passport_number, const std::string& date_of_birth,
        const std::string& nationality, const std::string& foreign_passport_number)
        : Passport(full_name, passport_number, date_of_birth, nationality), foreign_passport_number(foreign_passport_number) {}

    void addVisa(const std::string& visa_info) {
        visas.push_back(visa_info);
    }

    void displayInfo() const {
        Passport::displayInfo();
        std::cout << "Foreign Passport Number: " << foreign_passport_number << std::endl;
        std::cout << "Visas:" << std::endl;
        for (const std::string& visa : visas) {
            std::cout << "- " << visa << std::endl;
        }
    }

private:
    std::string foreign_passport_number;
    std::vector<std::string> visas;
};

int main() {
    // Создаем обычный паспорт
    Passport passport("Иван Иванович Иванский", "AA35283", "01.01.1990", "Украинец");
    passport.displayInfo();

    // Создаем заграничный паспорт с визами
    ForeignPassport foreignPassport("Иван Иванович", "AA123456", "01.01.1990", "Украинец", "AB789012");
    foreignPassport.addVisa("США, действительна до 31.12.2023");
    foreignPassport.addVisa("Германия, действительна до 30.06.2023");
    foreignPassport.displayInfo();

    return 0;
}
