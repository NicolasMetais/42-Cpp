#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void testDestructors() {
    std::cout << "Test: Gestion des destructeurs." << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* char1 = new Character("Character1");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    char1->equip(ice);
    char1->equip(cure);

    delete char1;
    delete src;
}


void testMateriaSourceInterface() {
    std::cout << "Test: IMateriaSource." << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    if (ice && ice->gettype() == "ice") {
        std::cout << "ice cree" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    if (cure && cure->gettype() == "cure") {
        std::cout << "cure cree" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }

    delete ice;
    delete cure;
    delete src;
}


void testUnequip() {
    std::cout << "Test: Unequip" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* char1 = new Character("Character1");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    char1->equip(ice);
    char1->equip(cure);

    ICharacter* char2 = new Character("Character2");
    char1->use(0, *char2);
    char1->use(1, *char2);

	char1->unequip(0);
    char1->unequip(1);

    char1->use(0, *char2);
    char1->use(1, *char2);

    delete char1;
    delete char2;
    delete src;
	delete ice;
	delete cure;
}


void testCharacterAssignmentAndCopy() {
    std::cout << "Test: Assignation et copie de Character." << std::endl;

    ICharacter* original = new Character("Original");
    ICharacter* copy = new Character("Copy");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    original->equip(ice);
    original->equip(cure);

    *copy = *original;

    ICharacter* target = new Character("Target");
    copy->use(0, *target);
    copy->use(1, *target);

    delete target;
    delete copy;
    delete original;
    delete src;
}


void testCharacterAndMateriaSource() {
    std::cout << "Test: Character et MateriaSource." << std::endl;

    IMateriaSource* src = new MateriaSource();
    ICharacter* char1 = new Character("Character1");

    std::cout << "template de materia" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "Création de Materia" << std::endl;
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");

    char1->equip(ice);
    char1->equip(cure);

    std::cout << "Use de Materia." << std::endl;
    ICharacter* char2 = new Character("Character2");
    char1->use(0, *char2);
    char1->use(1, *char2);

    delete char1;
    delete char2;
    delete src;
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	testCharacterAndMateriaSource();
	testCharacterAssignmentAndCopy();
	testUnequip();
	testMateriaSourceInterface();
	testDestructors();
return 0;
}
