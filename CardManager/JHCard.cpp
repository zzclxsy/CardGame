#include "JHCard.h"

JHCard::JHCard(E_CardSuit suit, E_CardNumber number)
{
    m_suit = suit;
    m_number = number;
}

JHCard::E_CardSuit JHCard::GetCardSuit()
{
    return m_suit;
}

JHCard::E_CardNumber JHCard::GetCardNumber()
{
    return m_number;
}
