class ParkingSystem {
public:
vector<int>vect;
    ParkingSystem(int big, int medium, int small) {
        vect = {big,medium,small};
    }
    
    bool addCar(int carType) {
        return vect[carType-1]>0 ? vect[carType-1]-- >0:false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */