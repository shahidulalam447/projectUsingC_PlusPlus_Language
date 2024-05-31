// #include<bits/stdc++.h>
// using namespace std;

/* The Employee class represents individual employees with their name and salary, 
adhering to the Single Responsibility Principle. */

#include <iostream>
#include <vector>
#include <memory>

// Implement a basic employee management system demonstrating SOLID principles.

// Single Responsibility Principle: Employee class has a single responsibility
class Employee {
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}

    const std::string& getName() const { return name; }
    double getSalary() const { return salary; }

private:
    std::string name;
    double salary;
};

// Open/Closed Principle: EmployeeReport is open for extension but closed for modification
class EmployeeReport {
public:
    virtual void generateReport(const std::vector<Employee>& employees) = 0;
};

// The TextReport class generates a textual representation of the employee report.
class TextReport : public EmployeeReport {
public:
    void generateReport(const std::vector<Employee>& employees) override {
        std::cout << "Employee Report:\n";
        for (const auto& employee : employees) {
            std::cout << "Name: " << employee.getName() << ", Salary: " << employee.getSalary() << "\n";
        }
    }
};

// Liskov Substitution Principle: Derived classes can be substituted for base classes
class HtmlReport : public EmployeeReport {
public:
    void generateReport(const std::vector<Employee>& employees) override {
        std::cout << "<html><body><h1>Employee Report</h1><ul>";
        for (const auto& employee : employees) {
            std::cout << "<li>Name: " << employee.getName() << ", Salary: " << employee.getSalary() << "</li>";
        }
        std::cout << "</ul></body></html>";
    }
};

// Interface Segregation Principle: Reporting interface is not too large
// Dependency Inversion Principle: High-level modules should not depend on low-level modules
class EmployeeManager {
public:
    // EmployeeManager manages employees and utilizes different report formats through the EmployeeReport interface.
    EmployeeManager(std::shared_ptr<EmployeeReport> report) : report(report) {}

    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    void generateReport() {
        report->generateReport(employees);
    }

private:
    std::vector<Employee> employees;
    std::shared_ptr<EmployeeReport> report;
};

int main() {
    // Initialize the manager with a TextReport.
    EmployeeManager manager(std::make_shared<TextReport>());
    manager.addEmployee(Employee("John Doe", 50000));
    manager.addEmployee(Employee("Jane Smith", 60000));
    manager.generateReport();

    // Switch to HTML report
    manager = EmployeeManager(std::make_shared<HtmlReport>());
    manager.addEmployee(Employee("Alice Johnson", 70000));
    manager.generateReport();

    return 0;
}
