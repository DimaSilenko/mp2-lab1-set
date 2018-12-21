#pragma once

#include <iostream>

using namespace std;

typedef unsigned int UInt;

class TBitField
{
private:
  int  bitLen; // длина битового поля - макс. к-во битов
  UInt *pMem; // память для представления битового поля
  int  memLen; // к-во эл-тов Мем для представления бит.поля
  // методы реализации
  int   GetMemIndex(const int n) const; // индекс в pМем для бита n       (#О2)
  UInt GetMemMask (const int n) const; // битовая маска для бита n       (#О3)

public:
  TBitField(int len);                //                                   (#О1)
  TBitField(const TBitField &bf);    //                                   (#П1)
  ~TBitField();                      //                                    (#С)

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)           (#О)
  void SetBit(const int n);       // установить бит                       (#О4)
  void ClrBit(const int n);       // очистить бит                         (#П2)
  int  GetBit(const int n) const; // получить значение бита               (#Л1)

  // битовые операции
  int operator==(const TBitField &bf) const; // сравнение                 (#О5)
  int operator!=(const TBitField &bf) const; // сравнение
  TBitField& operator=(const TBitField &bf); // присваивание              (#П3)
  TBitField  operator|(const TBitField &bf); // операция "или"            (#О6)
  TBitField  operator&(const TBitField &bf); // операция "и"              (#Л2)
  TBitField  operator~(void);                // отрицание                  (#С)

  friend istream &operator>>(istream &istr, TBitField &bf);       //      (#О7)
  friend ostream &operator<<(ostream &ostr, const TBitField &bf); //      (#П4)
};