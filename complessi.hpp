#pragma once  // fa in modo che il file venga letto e processato una sola volta dal compilatore, anche se viene incluso più volte in diversi punti del programma.
#include <concepts>
#include <iostream>

template<typename T> // oppure potrei utilizzare template<std::floating_point T> dopo aver fatto  #include <concepts>
requires std::same_as<T, double> || std::same_as<T, float>

class numero_complesso{
    T reale;
    T immaginaria; // questi sono gli attributi privati della classe 

    public:

    numero_complesso(){ // costruttore di default
        reale = 0.0;
        immaginaria = 0.0;
    }

    numero_complesso(T r, T i){ // costruttore personalizzato
        reale = r;
        immaginaria = i;
    }

    numero_complesso coniugato() const { // metodo coniugato
        return numero_complesso(reale, -immaginaria);
    }

    T parte_reale() const { // metodo che restituisce la parte reale
        return reale;
    }

    T parte_immaginaria() const { // metodo che restituisce la parte immaginaria
        return immaginaria;    
    }

    numero_complesso& operator+=(const numero_complesso& altro){// creo l'operatore +=
        T a = reale;
        T b = immaginaria;
        T c = altro.reale;
        T d = altro.immaginaria;
        reale = a+c;
        immaginaria = b+d;
        return *this;
    }

    numero_complesso operator+(const numero_complesso& altro) const {// creo l'operatore +
        numero_complesso numero = *this;
        numero += altro;
        return numero;
    }

    numero_complesso operator*=(const numero_complesso& altro ){// creo l'operatore *=
        T a = reale;
        T b = immaginaria;
        T c = altro.reale;
        T d = altro.immaginaria;
        reale = a*c - b*d;
        immaginaria = a*d + b*c;
        return *this;    
    }

    numero_complesso operator*(const numero_complesso& altro) const {//creo l'operatore *
        numero_complesso numero = *this;
        numero *= altro;
        return numero;    
    }

};





//somma con un F messo a sinistra
template<typename T> numero_complesso<T>

operator+(const T& i, const numero_complesso<T>& c)
{
T a= c.return_r();
T b= c.return_i(); //METTI LE TONDE PER CHIAMARE LA FUNZIONE RETURN!!
return numero_complesso(a+i,b);
}

//somma con un F messo a destra
template<typename T> numero_complesso<T>

operator+(const numero_complesso<T>& c, const T& i)
{
T a= c.return_r();
T b= c.return_i(); //METTI LE TONDE PER CHIAMARE LA FUNZIONE RETURN!!
return numero_complesso(a+i,b);
}


//prodotto con un F messo a sinistra
template<typename T> numero_complesso<T>

operator*(const T& i, const numero_complesso<T>& c)
{
T a= c.return_r();
T b= c.return_i(); //METTI LE TONDE PER CHIAMARE LA FUNZIONE RETURN!!
return numero_complesso(a*i,b*i);
}


//prodotto con un F messo a destra
template<typename T> numero_complesso<T>

operator*(const numero_complesso<T>& c, const T& i)
{
T a= c.return_r();
T b= c.return_i(); //METTI LE TONDE PER CHIAMARE LA FUNZIONE RETURN!!
return numero_complesso(a*i,b*i);
}


// ora creo l'operatore << per poter stampare i numeri complessi 

template<typename T> 
std::ostream& operator<<(std::ostream& os, const numero_complesso<T>& n){
    if(n.parte_immaginaria() > 0){
        os << n.parte_reale()<< "+" <<n.parte_immaginaria()<< "i";
    }else if(n.parte_immaginaria() == 0){
        os << n.parte_reale();
    }else{
        os << n.parte_reale()<< "" <<n.parte_immaginaria()<< "i";
    }
    
    return os;
}