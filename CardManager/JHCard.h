#ifndef JHCARD_H
#define JHCARD_H

class JHCard
{
public:
    typedef enum{
        Card_Heart,
        Card_Diamond,
        Card_Spade,
        Card_Club,
        Card_Joker
    }E_CardSuit;

    typedef enum{
        Card_A,
        Card_1,
        Card_2,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_0,
        Card_J,
        Card_Q,
        Card_K,
        Card_SmallJoker,
        Card_BigJoker,
    }E_CardNumber ;

    JHCard(E_CardSuit suit, E_CardNumber number);
    E_CardSuit GetCardSuit();
    E_CardNumber GetCardNumber();

private:
    E_CardSuit m_suit;
    E_CardNumber m_number;
};

#endif // JHCARD_H
