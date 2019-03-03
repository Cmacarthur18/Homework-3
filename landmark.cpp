
#include <iostream>
using namespace std;
#include <string>

class Landmark{
public:
    Landmark(string name): m_name(name){};
    virtual string color() const{
        return "yellow";
    }
   
    virtual string icon() const = 0;
    
    string name() const {
        return m_name;
    }
    
    
    virtual ~Landmark() {};
    
private:
    string m_name;
};

class Restaurant :public Landmark{
public:
    Restaurant(string name, int people):Landmark(name){
        m_people = people;
        if(people < 40)
            m_icon = "small knife/fork";
        else
            m_icon = "large knife/fork";
    }
    string icon() const{
        return m_icon;
    }
    
    virtual ~Restaurant(){
        cout << "Destroying the restaurant " << name() << "." << endl;
    }
    
    
private:
   int m_people;
   string m_icon;
    
};

class Hotel: public Landmark{
public:
    Hotel(string name):Landmark(name){
    }
     string icon() const{
        return "bed";
    }
    virtual~Hotel(){
        cout << "Destroying the hotel " << name() << "." << endl;
    }
private:
    
};

class Hospital:public Landmark{
public:
    Hospital(string name):Landmark(name){
        
    }
    string icon() const{
        return "H";
    }
    string color() const{
        return "blue";
    }
    virtual ~Hospital(){
        cout << "Destroying the hospital " << name() << "." << endl;
    }
private:

};


void display(const Landmark* lm)
{
    cout << "Display a " << lm->color() << " " << lm->icon() << " icon for "
    << lm->name() << "." << endl;
}


//int main()
//{
//    Landmark* landmarks[4];
//    landmarks[0] = new Hotel("Westwood Rest Good");
//
//
//    // Restaurants have a name and seating capacity.  Restaurants with a
//    // capacity under 40 have a small knife/fork icon; those with a capacity
//    // 40 or over have a large knife/fork icon.
//    landmarks[1] = new Restaurant("Bruin Bite", 30);
//    landmarks[2] = new Restaurant("La Morsure de l'Ours", 100);
//    landmarks[3] = new Hospital("UCLA Medical Center");
//
//    cout << "Here are the landmarks." << endl;
//    for (int k = 0; k < 4; k++)
//        display(landmarks[k]);
//
//     //Clean up the landmarks before exiting
//    cout << "Cleaning up." << endl;
//    for (int k = 0; k < 4; k++)
//        delete landmarks[k];
//
//    
//
//}
