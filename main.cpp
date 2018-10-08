#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

/*
 1 str
 2 dex
 3 con
 4 int
 5 wis
 6 cha
 */


int main() {
    srand((int)time(NULL));     //initialize random seed
    
    //the lunatic
    
    int n = 1;
    
    /*
    cout << "Enter number of stat sets to generate (1 to 50 inclusive): ";
    cin >> n;
    if (n < 1 || n > 50) {
        cout << "Invalid input" << endl;
        return 0;
    }
     */
    
    double trolls = 0, tSTR = 0, tDEX = 0, tCON = 0, tINT = 0, tWIS = 0, tCHA = 0;
    
    double *STR = new double, *DEX = new double, *CON = new double, *INT = new double, *WIS = new double, *CHA = new double, *sk = new double;
    
    for (int i = 0; i < n; i++) {
        
        int done = 0, d20 = 0, d6 = 0, xloop = 1;
        
        *STR = *DEX = *CON = *INT = *WIS = *CHA = *sk = 0;
        
        while (done < 6) {
            
            d20 = (rand() % 20) + 1;
            d6 = (rand() % 6) + 1;
            
            printf("Loop %d: d20 rolled %d, d6 rolled %d\n", xloop, d20, d6);           //loop debugger
            
            switch (d6) {
                case 1:
                    sk = STR;
                    break;
                case 2:
                    sk = DEX;
                    break;
                case 3:
                    sk = CON;
                    break;
                case 4:
                    sk = INT;
                    break;
                case 5:
                    sk = WIS;
                    break;
                case 6:
                    sk = CHA;
                    break;
            }
            
            if (*sk == 0) {
                done++;
                *sk = d20;
            } else {
                *sk = ceil((*sk + d20)/2);
            }
            
            xloop++;
            
        }
        
        
        //print stats and roll number for one set
        
        
        cout << endl;
        cout << "STR: " << *STR << ", DEX: " << *DEX << ", CON: " << *CON << ", INT: " << *INT << ", WIS: " << *WIS << ", CHA: " << *CHA << endl;
        cout << "Rolled " << xloop - 1 << " times" << endl;
        
        
        //print stats as raw data w/tab in between
        /*
        cout << *STR << "\t" << *DEX << "\t" << *CON << "\t" << *INT << "\t" << *WIS << "\t" << *CHA << "\t" << xloop - 1 << endl;
         */
        
        //running total calculations
        
        /*
        trolls += (xloop - 1);
        tSTR += *STR;
        tDEX += *DEX;
        tCON += *CON;
        tINT += *INT;
        tWIS += *WIS;
        tCHA += *CHA;
         */
    }
    
    //avg print
    
    /*
    cout << endl;
    cout << "Average stats: STR: " << tSTR/n << ", DEX: " << tDEX/n << ", CON: " << tCON/n << ", INT: " << tINT/n << ", WIS: " << tWIS/n << ", CHA: " << tCHA/n << endl;
    cout << endl;
    cout << "Average of average stats: " << (tSTR/n + tDEX/n + tCON/n + tINT/n + tWIS/n + tCHA/n)/6 << endl;
    cout << endl;
    cout << "Average number of rolls: " << trolls/n << endl;
    */
    
    delete STR;
    delete DEX;
    delete CON;
    delete INT;
    delete WIS;
    delete CHA;
    
}
