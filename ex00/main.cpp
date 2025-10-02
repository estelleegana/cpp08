#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


// Codes couleur pour l'affichage
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printTestHeader(const std::string& testName) {
    std::cout << "\n" << BLUE << "========== " << testName << " ==========" << RESET << std::endl;
}

void testVector() {
    printTestHeader("TEST VECTOR");
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(100);
    
    std::cout << "Contenu du vector: 1, 5, 10, 42, 100" << std::endl;
    
    // Test 1: Élément trouvé au début
    try {
        std::vector<int>::iterator it = easyfind(vec, 1);
        std::cout << GREEN << "✓ Trouvé 1: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    // Test 2: Élément trouvé au milieu
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << GREEN << "✓ Trouvé 42: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    // Test 3: Élément trouvé à la fin
    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << GREEN << "✓ Trouvé 100: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    // Test 4: Élément non trouvé
    try {
        easyfind(vec, 999);
        std::cout << RED << "✗ Ne devrait pas trouver 999!" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << GREEN << "✓ Exception attendue pour 999: " << e.what() << RESET << std::endl;
    }
}

void testList() {
    printTestHeader("TEST LIST");
    
    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(14);
    lst.push_back(21);
    lst.push_back(28);
    
    std::cout << "Contenu de la list: 7, 14, 21, 28" << std::endl;
    
    // Test 1: Élément trouvé
    try {
        std::list<int>::iterator it = easyfind(lst, 14);
        std::cout << GREEN << "✓ Trouvé 14: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    // Test 2: Élément non trouvé
    try {
        easyfind(lst, 50);
        std::cout << RED << "✗ Ne devrait pas trouver 50!" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << GREEN << "✓ Exception attendue pour 50: " << e.what() << RESET << std::endl;
    }
}

void testDeque() {
    printTestHeader("TEST DEQUE");
    
    std::deque<int> deq;
    deq.push_back(3);
    deq.push_back(6);
    deq.push_back(9);
    deq.push_back(12);
    deq.push_back(15);
    
    std::cout << "Contenu de la deque: 3, 6, 9, 12, 15" << std::endl;
    
    // Test 1: Élément trouvé
    try {
        std::deque<int>::iterator it = easyfind(deq, 9);
        std::cout << GREEN << "✓ Trouvé 9: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    // Test 2: Élément non trouvé
    try {
        easyfind(deq, 100);
        std::cout << RED << "✗ Ne devrait pas trouver 100!" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << GREEN << "✓ Exception attendue pour 100: " << e.what() << RESET << std::endl;
    }
}

void testEmptyContainer() {
    printTestHeader("TEST CONTENEUR VIDE");
    
    std::vector<int> empty;
    std::cout << "Contenu du vector: (vide)" << std::endl;
    
    try {
        easyfind(empty, 42);
        std::cout << RED << "✗ Ne devrait rien trouver dans un conteneur vide!" << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << GREEN << "✓ Exception attendue pour conteneur vide: " << e.what() << RESET << std::endl;
    }
}

void testDuplicates() {
    printTestHeader("TEST DOUBLONS (première occurrence)");
    
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(20);
    vec.push_back(5);
    
    std::cout << "Contenu du vector: 5, 10, 5, 20, 5" << std::endl;
    std::cout << "Recherche de 5 (devrait trouver la première occurrence)" << std::endl;
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << GREEN << "✓ Trouvé 5 à la position: " << (it - vec.begin()) << RESET << std::endl;
        if (it == vec.begin()) {
            std::cout << GREEN << "✓ C'est bien la première occurrence!" << RESET << std::endl;
        } else {
            std::cout << YELLOW << "⚠ Ce n'est pas la première occurrence!" << RESET << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
}

void testNegativeNumbers() {
    printTestHeader("TEST NOMBRES NÉGATIFS");
    
    std::list<int> lst;
    lst.push_back(-50);
    lst.push_back(-10);
    lst.push_back(0);
    lst.push_back(10);
    lst.push_back(50);
    
    std::cout << "Contenu de la list: -50, -10, 0, 10, 50" << std::endl;
    
    try {
        std::list<int>::iterator it = easyfind(lst, -10);
        std::cout << GREEN << "✓ Trouvé -10: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
    
    try {
        std::list<int>::iterator it = easyfind(lst, 0);
        std::cout << GREEN << "✓ Trouvé 0: " << *it << RESET << std::endl;
    } catch (std::exception& e) {
        std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << YELLOW << "\n╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║   TESTS POUR EASYFIND - MODULE 08      ║" << RESET << std::endl;
    std::cout << YELLOW << "╚════════════════════════════════════════╝" << RESET << std::endl;
    
    testVector();
    testList();
    testDeque();
    testEmptyContainer();
    testDuplicates();
    testNegativeNumbers();
    
    std::cout << "\n" << YELLOW << "╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║          TESTS TERMINÉS                ║" << RESET << std::endl;
    std::cout << YELLOW << "╚════════════════════════════════════════╝" << RESET << "\n" << std::endl;
    
    return 0;
}