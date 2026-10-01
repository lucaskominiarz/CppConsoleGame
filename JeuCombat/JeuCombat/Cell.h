#pragma once

class Cell // classe de base de laquelle héritent les différentes unités
{
protected:
    int hp;
    int maxHp;
    bool isJ1;
    int range;
    int attackPower;
    int moveSpeed;

public: 
    Cell(int hp = 0, bool isJ1 = false, int range = 0, int attackPower = 0, int moveSpeed = 0);
    virtual ~Cell() = default;
    virtual bool IsEmpty() const;
    int GetHp() const;
    bool GetPlayer() const;
    int GetRange() const;
    int GetAttackPower() const;
    virtual bool TakeDamage(int damage);
    int GetMoveSpeed() const;
    void Heal(int amount);
    virtual bool IsNeutral() const;

    bool CanMoveTo(int sourceRow, int sourceCol, int targetRow, int targetCol) const;
    virtual bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) = 0;
    virtual bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const = 0;

    static int DistanceSquared(int r1, int c1, int r2, int c2);
};