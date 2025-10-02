#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

// Codes couleur
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

void printTestHeader(const std::string& testName) {
    std::cout << "\n" << BLUE << "========== " << testName << " ==========" << RESET << std::endl;
}

void testBasicExample() {
    printTestHeader("TEST DE L'EXEMPLE DU SUJET");
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Nombres ajoutés: 6, 3, 17, 9, 11" << std::endl;
    // std::cout << "shortestSpan: " << sp.shortestSpan() << " (attendu: 2)" << std::endl;
    // std::cout << "longestSpan: " << sp.longestSpan() << " (attendu: 14)" << std::endl;
}

// void testFullException() {
//     printTestHeader("TEST EXCEPTION SPAN PLEIN");
    
//     Span sp(3);
//     sp.addNumber(1);
//     sp.addNumber(2);
//     sp.addNumber(3);
    
//     std::cout << "Span de taille 3, rempli avec 3 nombres" << std::endl;
    
//     try {
//         sp.addNumber(4); // Devrait lever une exception
//         std::cout << RED << "✗ Erreur: devrait lever une exception!" << RESET << std::endl;
//     } catch (Span::FullException& e) {
//         std::cout << GREEN << "✓ Exception attendue: " << e.what() << RESET << std::endl;
//     }
// }

// void testNoSpanException() {
//     printTestHeader("TEST EXCEPTION PAS ASSEZ DE NOMBRES");
    
//     // Test avec 0 nombre
//     Span sp1(10);
//     std::cout << "Test avec 0 nombre:" << std::endl;
//     try {
//         sp1.shortestSpan();
//         std::cout << RED << "✗ Erreur: devrait lever une exception!" << RESET << std::endl;
//     } catch (Span::NoSpanException& e) {
//         std::cout << GREEN << "✓ Exception attendue: " << e.what() << RESET << std::endl;
//     }
    
//     // Test avec 1 nombre
//     Span sp2(10);
//     sp2.addNumber(42);
//     std::cout << "\nTest avec 1 seul nombre:" << std::endl;
//     try {
//         sp2.longestSpan();
//         std::cout << RED << "✗ Erreur: devrait lever une exception!" << RESET << std::endl;
//     } catch (Span::NoSpanException& e) {
//         std::cout << GREEN << "✓ Exception attendue: " << e.what() << RESET << std::endl;
//     }
// }

// void testTwoNumbers() {
//     printTestHeader("TEST AVEC 2 NOMBRES");
    
//     Span sp(10);
//     sp.addNumber(5);
//     sp.addNumber(15);
    
//     std::cout << "Nombres: 5, 15" << std::endl;
//     std::cout << "shortestSpan: " << sp.shortestSpan() << " (attendu: 10)" << std::endl;
//     std::cout << "longestSpan: " << sp.longestSpan() << " (attendu: 10)" << std::endl;
// }

// void testNegativeNumbers() {
//     printTestHeader("TEST AVEC NOMBRES NÉGATIFS");
    
//     Span sp(5);
//     sp.addNumber(-10);
//     sp.addNumber(-5);
//     sp.addNumber(0);
//     sp.addNumber(5);
//     sp.addNumber(10);
    
//     std::cout << "Nombres: -10, -5, 0, 5, 10" << std::endl;
//     std::cout << "shortestSpan: " << sp.shortestSpan() << " (attendu: 5)" << std::endl;
//     std::cout << "longestSpan: " << sp.longestSpan() << " (attendu: 20)" << std::endl;
// }

// void testDuplicates() {
//     printTestHeader("TEST AVEC DOUBLONS");
    
//     Span sp(5);
//     sp.addNumber(5);
//     sp.addNumber(5);
//     sp.addNumber(10);
//     sp.addNumber(10);
//     sp.addNumber(20);
    
//     std::cout << "Nombres: 5, 5, 10, 10, 20" << std::endl;
//     std::cout << "shortestSpan: " << sp.shortestSpan() << " (attendu: 0)" << std::endl;
//     std::cout << "longestSpan: " << sp.longestSpan() << " (attendu: 15)" << std::endl;
// }

// void testAddRange() {
//     printTestHeader("TEST ADDRANGE AVEC ITÉRATEURS");
    
//     Span sp(10);
    
//     std::vector<int> vec;
//     vec.push_back(1);
//     vec.push_back(2);
//     vec.push_back(3);
//     vec.push_back(4);
//     vec.push_back(5);
    
//     std::cout << "Ajout de 5 nombres via addRange: 1, 2, 3, 4, 5" << std::endl;
//     sp.addRange(vec.begin(), vec.end());
    
//     std::cout << "shortestSpan: " << sp.shortestSpan() << " (attendu: 1)" << std::endl;
//     std::cout << "longestSpan: " << sp.longestSpan() << " (attendu: 4)" << std::endl;
// }

// void testAddRangeOverflow() {
//     printTestHeader("TEST ADDRANGE DÉPASSEMENT");
    
//     Span sp(5);
    
//     std::vector<int> vec;
//     for (int i = 0; i < 10; ++i) {
//         vec.push_back(i);
//     }
    
//     std::cout << "Tentative d'ajouter 10 nombres dans un Span de taille 5" << std::endl;
    
//     try {
//         sp.addRange(vec.begin(), vec.end());
//         std::cout << RED << "✗ Erreur: devrait lever une exception!" << RESET << std::endl;
//     } catch (Span::FullException& e) {
//         std::cout << GREEN << "✓ Exception attendue: " << e.what() << RESET << std::endl;
//     }
// }

// void testLargeSpan() {
//     printTestHeader("TEST AVEC 10,000 NOMBRES");
    
//     Span sp(10000);
//     std::srand(std::time(0));
    
//     std::cout << "Ajout de 10,000 nombres aléatoires..." << std::endl;
    
//     for (int i = 0; i < 10000; ++i) {
//         sp.addNumber(std::rand());
//     }
    
//     std::cout << GREEN << "✓ 10,000 nombres ajoutés avec succès" << RESET << std::endl;
    
//     try {
//         int shortest = sp.shortestSpan();
//         int longest = sp.longestSpan();
//         std::cout << "shortestSpan: " << shortest << std::endl;
//         std::cout << "longestSpan: " << longest << std::endl;
//         std::cout << GREEN << "✓ Calculs réussis sur 10,000 nombres" << RESET << std::endl;
//     } catch (std::exception& e) {
//         std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
//     }
// }

// void testVeryLargeSpan() {
//     printTestHeader("TEST AVEC 100,000 NOMBRES (BONUS)");
    
//     Span sp(100000);
    
//     std::cout << "Ajout de 100,000 nombres via addRange..." << std::endl;
    
//     std::vector<int> vec;
//     std::srand(std::time(0) + 42);
    
//     for (int i = 0; i < 100000; ++i) {
//         vec.push_back(std::rand());
//     }
    
//     sp.addRange(vec.begin(), vec.end());
//     std::cout << GREEN << "✓ 100,000 nombres ajoutés avec succès" << RESET << std::endl;
    
//     try {
//         int shortest = sp.shortestSpan();
//         int longest = sp.longestSpan();
//         std::cout << "shortestSpan: " << shortest << std::endl;
//         std::cout << "longestSpan: " << longest << std::endl;
//         std::cout << GREEN << "✓ Calculs réussis sur 100,000 nombres" << RESET << std::endl;
//     } catch (std::exception& e) {
//         std::cout << RED << "✗ Erreur: " << e.what() << RESET << std::endl;
//     }
// }

// void testCopyConstructor() {
//     printTestHeader("TEST CONSTRUCTEUR DE COPIE");
    
//     Span sp1(5);
//     sp1.addNumber(1);
//     sp1.addNumber(2);
//     sp1.addNumber(3);
    
//     Span sp2(sp1);
    
//     std::cout << "sp1 shortestSpan: " << sp1.shortestSpan() << std::endl;
//     std::cout << "sp2 shortestSpan: " << sp2.shortestSpan() << std::endl;
    
//     if (sp1.shortestSpan() == sp2.shortestSpan()) {
//         std::cout << GREEN << "✓ Copie réussie" << RESET << std::endl;
//     } else {
//         std::cout << RED << "✗ Erreur de copie" << RESET << std::endl;
//     }
// }

// void testAssignmentOperator() {
//     printTestHeader("TEST OPÉRATEUR D'AFFECTATION");
    
//     Span sp1(5);
//     sp1.addNumber(10);
//     sp1.addNumber(20);
//     sp1.addNumber(30);
    
//     Span sp2(10);
//     sp2 = sp1;
    
//     std::cout << "sp1 longestSpan: " << sp1.longestSpan() << std::endl;
//     std::cout << "sp2 longestSpan: " << sp2.longestSpan() << std::endl;
    
//     if (sp1.longestSpan() == sp2.longestSpan()) {
//         std::cout << GREEN << "✓ Affectation réussie" << RESET << std::endl;
//     } else {
//         std::cout << RED << "✗ Erreur d'affectation" << RESET << std::endl;
//     }
// }

int main() {
    std::cout << YELLOW << "\n╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║      TESTS POUR SPAN - MODULE 08       ║" << RESET << std::endl;
    std::cout << YELLOW << "╚════════════════════════════════════════╝" << RESET << std::endl;
    
    testBasicExample();
    // testFullException();
    // testNoSpanException();
    // testTwoNumbers();
    // testNegativeNumbers();
    // testDuplicates();
    // testAddRange();
    // testAddRangeOverflow();
    // testLargeSpan();
    // testVeryLargeSpan();
    // testCopyConstructor();
    // testAssignmentOperator();
    
    std::cout << "\n" << YELLOW << "╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << YELLOW << "║          TESTS TERMINÉS                ║" << RESET << std::endl;
    std::cout << YELLOW << "╚════════════════════════════════════════╝" << RESET << "\n" << std::endl;
    
    return 0;
}