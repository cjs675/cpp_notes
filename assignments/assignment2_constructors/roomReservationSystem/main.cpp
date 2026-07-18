#include <iostream> 

using namespace std;

class hotelRoom{

private: 
    int roomNumber;
    string roomType;
    double pricePerNight; 

    // initialize bool value to false by default 
    // else, value will retain "garbage" data 
    bool isReserved = false;


public: 
    
    // parameterized constructor 
    hotelRoom(int num, const string& type, double price, bool status) 
        : roomNumber(num), roomType(type), pricePerNight(price), isReserved(status) {
    }

    // destructor 
    ~hotelRoom() { 
        cout << "\nHotel Room Object destroyed: " << roomNumber << "\n";
    }

    // method to reserve a room 
    void reserveRoom() {
        // if isReserved = true, room is unavailable  
        // if isReserved = false, room is available 
        if (!isReserved) {
            cout << "\nRoom: " << roomNumber << " Successfully Reserved, Enjoy your stay.\n "; 

            // update state of room availability 
            isReserved = true;
        }  
        else {
            cout << "\nOur Apologies, Room: " << roomNumber << " is already booked.\n";
        }
    }

    // method to cancel reservation 
    void cancelReservation() {
        // check room reservation status
        if (isReserved) { 
            
            isReserved = false;
            cout << "Reservation for Room:  " << roomNumber << " has been cancelled.\n";
        } 
        else {
            cout << "No reservations for Room: " << roomNumber << " found.\n";
        }
    } 

    // method to display reservation details 
    void displayRoomDetails() {
        cout << "\n----Reservation Details -----\n";
        cout << "Room Number:        " << roomNumber << "\n";
        cout << "Room Type:          " << roomType << "\n";
        cout << "Price per Night:    " << pricePerNight << "\n";
        cout << "Reservation Status: " << (isReserved ? "Reserved" : "Not Reserved") << "\n";
    }
}; 


int main() {
    
    // instantiation of room objects setting values to parameterized constructor 
    hotelRoom room1(661, "Penthouse Suite", 1699.99, false);
    hotelRoom room2(532, "Luxury King Suite", 799.99, false);
    hotelRoom room3(159, "Double Queen Suite", 699.99, false);

    // calling of public method ( reserveRoom() ) on respective objects 
    room1.reserveRoom();
    room2.reserveRoom();   
    room3.reserveRoom(); 

    // method call to display aggregate reservation details
    room1.displayRoomDetails();
    room2.displayRoomDetails();
    room3.displayRoomDetails();
    
    // cancel one reservation & display resulting details  
    cout << "\n\n--------- Updated Reservation Details----------\n";
    room1.cancelReservation(); 
    room1.displayRoomDetails();
    room2.displayRoomDetails();
    room3.displayRoomDetails();

}
