#ifndef H_PLI_H
#define H_PLI_H
#include <unordered_map>
#include "CarteInterface.h"
#include <memory>
class Plis{
public :

	virtual unsigned int verifePlis(std::unordered_map<unsigned int, std::shared_ptr<CarteInterface>> carteDuPlie) = 0;

};
#endif 