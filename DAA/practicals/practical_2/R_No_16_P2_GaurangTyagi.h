#ifndef R_No_16_P2_GaurangTyagi_H
#define R_No_16_P2_GaurangTyagi_H

#include <vector>
#include <variant>
#include <string>

using value = std::variant<int,std::string,double>;

enum Type{
  INT,
  DOUBLE,
  STRING
};
struct Coltype{
  std::string name;
  Type type;
};

std::vector<Coltype> parseSchema(const std::string &);
value parseValue(const std::string &,const size_t,std::string&);
void readFile(const std::string &,const std::string &, std::vector<std::vector<value>>&);
void writeFile(const std::string &, const std::string &, std::vector<std::vector<value>>& data);
int getSortKey(const std::string &, const std::string &);

void insertionSort(std::vector<std::vector<value>>&,const std::string&,const std::string&);
#endif