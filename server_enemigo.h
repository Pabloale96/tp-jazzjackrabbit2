#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo {
    private:
        bool isAlive;
        int time;

    public:
        Enemigo();
        explicit Enemigo(bool alive);
        ~Enemigo();
        void sumTime();
        int getTime();
        bool checkTime();
        void changedAlive();

};
#endif
