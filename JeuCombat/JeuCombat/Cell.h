#pragma once

class Cell
{
protected:
    int hp;
    int maxHp;
    bool isJ1;
    int range;
    int attackPower;

public:
    Cell(int hp = 0, bool isJ1 = false, int range = 0, int attackPower = 0);
    virtual ~Cell() = default;
    virtual bool IsEmpty() const;
    int GetHp() const;
    bool GetPlayer() const;
    int GetRange() const;
    int GetAttackPower() const;
    virtual bool TakeDamage(int damage);

    virtual bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) = 0;
    virtual bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const = 0;

    static int DistanceSquared(int r1, int c1, int r2, int c2);
};