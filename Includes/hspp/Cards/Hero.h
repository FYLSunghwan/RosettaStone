// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_HERO_H
#define HEARTHSTONEPP_HERO_H

#include <hspp/Cards/Character.h>
#include <hspp/Cards/Weapon.h>

namespace Hearthstonepp
{
//!
//! \brief Hero structure.
//!
//! This structure inherits from Character structure.
//! Also, it stores weapon that can attack to enemy.
//!
struct Hero : public Character
{
    //! Constructs hero with given \p pCard.
    //! \param pCard A pointer to the card.
    Hero(const Card* pCard);

    Weapon* weapon;
};
}  // namespace Hearthstonepp

#endif