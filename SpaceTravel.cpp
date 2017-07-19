#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cctype>
using namespace std;
#include "format.h"

//  FUNCTION PROTOTYPES

// Function to determine the AUs a planet is from the sun
float BodesLaw (int planet);

// Function to convert Au to Miles
float AuToMiles (float Au);

// Function to Print Legend of Values the User Can Visit
void PrintLegend ();

// Function to Print Summary of Distances to Places Visited
void PrintSummary (float TotDist, int trips);

// Function to Print the Name of the Planet Corresponding to a Code
void PrintCode (int planet);


int main()
{

        cout.setf(ios::fixed,ios::floatfield);
        cout.setf(ios::showpoint);

        char quit;                // Used to Hold Whether User Wants to Quit
        float TotDist = 0.0;      // Total Distance Travelled on Mission
        float Dist = 0;           // Distance Between Any Two Bodies

        int prevCode;             // Holds Code of Last Place Visited
        int currCode = 3;         // Hold Code of Current Location
        int dest = 1;             // Destination Number Counter


        //  INSERT REST OF MAIN FUNCTION HERE

        cout << "***************   THE SPACE TRAVEL PROGRAM   ***************" << endl;
        cout << "\tEnter Destinations For Mission Using Key" << endl;
        cout << setw(38) << "Your Final Destination SHould Return you To Earth" << endl;

        PrintLegend ( );

        do
        {
                do
                {
                        do
                        {
                        cout << endl<< "Destionation #" << dest << " : ";
                        prevCode = currCode;
                        cin >> currCode;

        if (! ((currCode >= 1) && (currCode <= 10)) )
                cout << "Invalid Code Entered -- Try Again";

        } while ( ! ((currCode >= 1) && (currCode <= 10)) );
        cout << endl;
        dest++;

        Dist = fabs(BodesLaw(currCode) - BodesLaw(prevCode));

        TotDist += Dist;


        cout << "\tDistance From "; PrintCode(prevCode);
        cout << " To " ; PrintCode(currCode);
        cout << " =>   " << setprecision (2) << Dist << " Au " << endl;
        cout << "Miles"; AuToMiles(TotDist);

        } while (currCode != 3);

        PrintSummary (TotDist, dest - 2);
        cout << endl << "\t\tAny More Space Travel? (Y/N)"; cin >> quit;
        cout << endl;

        if ((quit) == 'N')
                break;

        } while (tolower(quit) != 'N');


        return 0;

}


//  INSERT FIVE FUNCTION BODIES HERE

float BodesLaw (int planet)
{
        int Position;
                if (planet == 1)
                        Position = 0;
                else if (planet == 2)
                        Position = 3;
                else if (planet == 9)
                        return 30.0;
                else
                        Position = 3;

                for (int i = 3; i<= planet; i++)
                {       Position = Position * 2;

                }
                return ((float)(Position + 4)) / (10.0);

}


float AuToMiles (float Au)
{

        return (Au * 9.2955807 *  pow(10,7));

}

void PrintLegend ()
{

        cout << endl << "%%%%%%%%%%%%%%%%%%%%%   LEGEND   %%%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << setw(20) << "      Mercury = 1 " << setw(32) << "  Venus = 2" << endl;
        cout << setw(20) << "       Earth  = 3 " << setw(32) << "   Mars = 4" << endl;
        cout << setw(20) << "Asteroid Belt = 5 " << setw(32) << "Jupiter = 6" << endl;
        cout << setw(20) << "       Saturn = 7 " << setw(32) << " Uranus = 8" << endl;
        cout << setw(20) << "      Neptune = 9 " << setw(32) << " Pluto = 10" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}

void PrintSummary (float TotDist, int trips)
{

        cout << endl << "***************** SUMMARY OF SPACE TRAVEL ***************" << endl;
        cout << setw(38) << "Total Places Visiting  => " << trips << endl;
        cout << setw(38) << "Distance Traveled (in AU)  => " << setprecision (2) << TotDist << endl;
        cout << setw(38) << "Distance Traveled (in Miles)  => " <<  setprecision (2) << AuToMiles(TotDist) << endl;
        cout << setw(38) << "Avg Distance Traveled (in AU)  => " << setprecision (2) << TotDist / (float) (trips + 1) << endl;
        cout << setw(38) << "Avg Distance Traveled (in Miles)  => " << setprecision (2) << AuToMiles(TotDist) / (float) (trips + 1)  << endl;
        cout << "********************************************************" << endl;


}

void PrintCode (int planet)
{

        if (planet == 1)
        {
                cout << "Mercury";
        }
        else if (planet == 2)
        {
                cout << "Venus";
        }
        else if (planet == 3)
        {
                cout << "Earth";
        }
        else if (planet == 4)
        {
                cout << "Mars";
        }
        else if (planet == 5)
        {
                cout << "Asteroid Belt";
        }
        else if (planet == 6)
        {
                cout << "Jupiter";
        }
        else if (planet == 7)
        {
                cout << "Saturn";
        }
        else if (planet == 8)
        {
                cout << "Uranus";
        }
        else if (planet == 9)
        {
                cout << "Neptune";
        }
        else if (planet == 10)
        {
                cout << "Pluto";
        }
}
