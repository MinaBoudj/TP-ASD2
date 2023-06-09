#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include <string>

struct Position{ 
    int x;
    int y;
};

class Personne {
    
    private:
        static int id;
        std::string name;
        int identifiant;
        Position position;

    public:
        Personne(std::string name);
        std::string getName() const;
        int getId() const;
        std::string get_initial();
        Position getPosition()const;
        void setPosition(int x, int y);
        void afficherPersonne();
        
    
};

#endif
