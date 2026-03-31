#pragma once
#include <iostream>
#include <concepts>

template<typename I> requires std::integral<I>
class razionali
{
    I numeratore;
    I denominatore;
    public:
         
        razionali()
        {
            numeratore = 2;
            denominatore = 3;
        }
        
        razionali(const I& num, const I& den)
        {
            numeratore = num;
            denominatore = den;
            riduzione();
        }

        I l_num() const {return numeratore;};
        I l_den() const {return denominatore;};

        razionali& operator +=(const razionali& other)
        {
            if (numeratore == 0 && denominatore == 0 || other.numeratore == 0 && other.denominatore == 0)
            {
                numeratore = 0;
                denominatore = 0;
            }

            else if (numeratore != 0 && denominatore == 0 || other.numeratore !=0 && other.denominatore == 0)
            {
                numeratore = 1;
                denominatore = 0;
            }

            else 
            {   
                int max_com_den = mcm(denominatore, other.denominatore);
                numeratore = (((max_com_den*numeratore)/denominatore)+((max_com_den*other.numeratore)/other.denominatore));
                denominatore = max_com_den;
            }

            return *this;
        }   
        
        razionali& operator-=(const razionali& other)
        {
            if (numeratore == 0 && denominatore == 0 || other.numeratore == 0 && other.denominatore == 0)
            {
                numeratore = 0;
                denominatore = 0;
            }

            else if (numeratore != 0 && denominatore == 0 || other.numeratore !=0 && other.denominatore == 0)
            {
                numeratore = 1;
                denominatore = 0;
            }

            else 
            {   
                int max_com_den = mcm(denominatore, other.denominatore);
                numeratore = (((max_com_den*numeratore)/denominatore)-((max_com_den*other.numeratore)/other.denominatore));
                denominatore = max_com_den;
            }

            return *this;
        }
        
        razionali operator+(const razionali& other)
        {
            razionali risultato = *this;
            risultato += other;
            return risultato;
        }

        

        razionali operator-(const razionali& other)
        {
            razionali risultato = *this;
            risultato -= other;
            return risultato;
        }

        razionali& operator*=(const razionali& other)
        {
            if (numeratore == 0 && denominatore == 0 || other.numeratore == 0 && other.denominatore == 0)
            {
                numeratore = 0;
                denominatore = 0;
            }

            else if (numeratore != 0 && denominatore == 0 || other.numeratore !=0 && other.denominatore == 0)
            {
                numeratore = 1;
                denominatore = 0;
            }

            else 
            {   
                numeratore = numeratore*other.numeratore;
                denominatore = denominatore*other.denominatore;
            }

            riduzione();
            return *this;
        }

        razionali operator*(const razionali&other) const 
        {
            razionali risultato = *this;
            risultato *=other;
            return risultato;
        }

        razionali& operator/=(const razionali& other)
        {
            if (numeratore == 0 && denominatore == 0 || other.numeratore == 0 && other.denominatore == 0)
            {
                numeratore = 0;
                denominatore = 0;
            }

            else if (numeratore != 0 && denominatore == 0 || other.numeratore !=0 && other.denominatore == 0)
            {
                numeratore = 1;
                denominatore = 0;
            }

            else 
            {  
                numeratore = numeratore*other.denominatore;
                denominatore = denominatore*other.numeratore;
            }

            riduzione();
            return *this;
        }

         razionali operator/(const razionali&other) const 
        {
            razionali risultato = *this;
            risultato /=other;
            return risultato;
        }
    private: 
        I mcd(I a, I b)
        {
            while(b !=0)
            { 
                int resto = a % b;
                a = b;
                b = resto;
            }
                
            if (a<0)
            {
                a = -a;
            }

            return a;
        }

        int mcm(I a, I b)
        {
            int min_cm = (a*b)/mcd(a,b);
            return min_cm;
        }

            void riduzione()
            {
                if (denominatore !=0)
                {
                    I max_cd = mcd(numeratore,denominatore);
                    numeratore = numeratore/max_cd;
                    denominatore = denominatore/max_cd;

                    if (denominatore<0) // controllo anche il segno così da evitare i vari casi
                    {
                        numeratore = -numeratore;
                        denominatore = -denominatore;
                    }

                }
            }
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const razionali<I>& n_razionale)
{
    if (n_razionale.l_den() == 0)
    {
        if(n_razionale.l_num() == 0)
        {
            os << "Nan";
        }
        else
        {
            os << "Inf";
        }
    }

    else
    {
        if(n_razionale.l_num() == 0)
        {
            os << 0;
        }
        else
        {
            if(n_razionale.l_den() == 1)
            {
                os << n_razionale.l_num();
            }

            else 
            {
                os << n_razionale.l_num() << "/" << n_razionale.l_den();
            }

        }
    }

return os;

}


        

        
