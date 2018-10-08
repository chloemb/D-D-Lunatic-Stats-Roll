#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <list>
#include <iterator>

using namespace std;

/*
 1 str
 2 dex
 3 con
 4 int
 5 wis
 6 cha
 */

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for (it = g.begin(); it != g.end(); it++) {
        cout << " - " << *it;
    }
}

int main() {
    srand((int)time(NULL));     //initialize random seed
    
    //the lunatic
    
    //roll stats one time
    
    int n = 20;
    
    
    //give a prompt to enter how many times Lunatic should be rolled
    
    cout << "Enter number of stat sets to generate (1 to 50 inclusive): ";
    cin >> n;
    if (n < 1 || n > 50) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    
    double trolls = 0, tSTR = 0, tDEX = 0, tCON = 0, tINT = 0, tWIS = 0, tCHA = 0;
    
    int lSTR = 21, hSTR = 0, lDEX = 21, hDEX = 0, lCON = 21, hCON = 0, lINT = 21, hINT = 0, lWIS = 21, hWIS = 0, lCHA = 21, hCHA = 0;
    
    double lAVG = 21, hAVG = 0;
    
    list <int> lSTRr, hSTRr, lDEXr, hDEXr, lCONr, hCONr, lINTr, hINTr, lWISr, hWISr, lCHAr, hCHAr, hAVGr, lAVGr;
    
    double *STR = new double, *DEX = new double, *CON = new double, *INT = new double, *WIS = new double, *CHA = new double, *sk = new double;
    
    for (int i = 0; i < n; i++) {
        
        int done = 0, d20 = 0, d6 = 0, xloop = 1;
        
        *STR = *DEX = *CON = *INT = *WIS = *CHA = *sk = 0;
        
        while (done < 6) {
            
            d20 = (rand() % 20) + 1;
            d6 = (rand() % 6) + 1;
            
            //print each d20 and d6 set
            /*
             printf("Loop %d: d20 rolled %d, d6 rolled %d\n", xloop, d20, d6);
            */
            
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
        
        double avg = (*STR + *DEX + *CON + *INT + *WIS + *CHA) / 6;
        
        //print stats and roll number for one set
        
        cout << endl;
        cout << "(" << i + 1 << ") " << "STR: " << *STR << ", DEX: " << *DEX << ", CON: " << *CON << ", INT: " << *INT << ", WIS: " << *WIS << ", CHA: " << *CHA << ", average: " << avg << endl;
        //cout << "Rolled " << xloop - 1 << " times" << endl;
        
        
        //print stats as raw data w/tab in between
        /*
        cout << *STR << "\t" << *DEX << "\t" << *CON << "\t" << *INT << "\t" << *WIS << "\t" << *CHA << "\t" << xloop - 1 << endl;
         */
        
        //total sum of each respective stat rolled over n stat sets
        trolls += (xloop - 1);
        tSTR += *STR;
        tDEX += *DEX;
        tCON += *CON;
        tINT += *INT;
        tWIS += *WIS;
        tCHA += *CHA;
        
        //keep track of lows and highs for each score
        
        if (*STR <= lSTR) {
            if (*STR < lSTR) {
                lSTR = *STR;
                lSTRr.clear();
            }
            lSTRr.push_back(i + 1);
        }
        
        if (*STR >= hSTR) {
            if (*STR > hSTR) {
                hSTR = *STR;
                hSTRr.clear();
            }
            hSTRr.push_back(i + 1);
        }
        
        if (*DEX <= lDEX) {
            if (*DEX < lDEX) {
                lDEX = *DEX;
                lDEXr.clear();
            }
            lDEXr.push_back(i + 1);
        }
        
        if (*DEX >= hDEX) {
            if (*DEX > hDEX) {
                hDEX = *DEX;
                hDEXr.clear();
            }
            hDEXr.push_back(i + 1);
        }
        
        if (*CON <= lCON) {
            if (*CON < lCON) {
                lCON = *CON;
                lCONr.clear();
            }
            lCONr.push_back(i + 1);
        }
        
        if (*CON >= hCON) {
            if (*CON > hCON) {
                hCON = *CON;
                hCONr.clear();
            }
            hCONr.push_back(i + 1);
        }
        
        if (*INT <= lINT) {
            if (*INT < lINT) {
                lINT = *INT;
                lINTr.clear();
            }
            lINTr.push_back(i + 1);
        }
        
        if (*INT >= hINT) {
            if (*INT > hINT) {
                hINT = *INT;
                hINTr.clear();
            }
            hINTr.push_back(i + 1);
        }
        
        if (*WIS <= lWIS) {
            if (*WIS < lWIS) {
                lWIS = *WIS;
                lWISr.clear();
            }
            lWISr.push_back(i + 1);
        }
        
        if (*WIS >= hWIS) {
            if (*WIS > hWIS) {
                hWIS = *WIS;
                hWISr.clear();
            }
            hWISr.push_back(i + 1);
        }
        
        if (*CHA <= lCHA) {
            if (*CHA < lCHA) {
                lCHA = *CHA;
                lCHAr.clear();
            }
            lCHAr.push_back(i + 1);
        }
        
        if (*CHA >= hCHA) {
            if (*CHA > hCHA) {
                hCHA = *CHA;
                hCHAr.clear();
            }
            hCHAr.push_back(i + 1);
        }
        
        if (avg <= lAVG) {
            if (avg < lAVG) {
                lAVG = avg;
                lAVGr.clear();
            }
            lAVGr.push_back(i + 1);
        }
        
        if (avg >= hAVG) {
            if (avg > hAVG) {
                hAVG = avg;
                hAVGr.clear();
            }
            hAVGr.push_back(i + 1);
        }
        
    }
    
    //calculate the average and print
    /*
    cout << endl;
    cout << "Average stats: STR: " << tSTR/n << ", DEX: " << tDEX/n << ", CON: " << tCON/n << ", INT: " << tINT/n << ", WIS: " << tWIS/n << ", CHA: " << tCHA/n << endl;
    cout << endl;
    cout << "Average of average stats: " << (tSTR/n + tDEX/n + tCON/n + tINT/n + tWIS/n + tCHA/n)/6 << endl;
    cout << endl;
    cout << "Average number of rolls: " << trolls/n << endl;
     */
    
    //highs and lows of each score as well as average score and which loop they were rolled on
    
    cout << endl;
    cout << "Additional information:" << endl;
    
    cout << "High average: " << hAVG << " (loop";
    showlist(hAVGr);
    cout << ")" << endl;
    
    cout << "High STR: " << hSTR << " (loop";
    showlist(hSTRr);
    cout << ")" << endl;
    
    cout << "High DEX: " << hDEX << " (loop";
    showlist(hDEXr);
    cout << ")" << endl;
    
    cout << "High CON: " << hCON << " (loop";
    showlist(hCONr);
    cout << ")" << endl;
    
    cout << "High INT: " << hINT << " (loop";
    showlist(hINTr);
    cout << ")" << endl;
    
    cout << "High WIS: " << hWIS << " (loop";
    showlist(hWISr);
    cout << ")" << endl;
    
    cout << "High CHA: " << hCHA << " (loop";
    showlist(hCHAr);
    cout << ")" << endl;
    
    cout << endl;
    
    cout << "Low average: " << lAVG << " (loop";
    showlist(lAVGr);
    cout << ")" << endl;
    
    cout << "Low STR: " << lSTR << " (loop";
    showlist(lSTRr);
    cout << ")" << endl;
    
    cout << "Low DEX: " << lDEX << " (loop";
    showlist(lDEXr);
    cout << ")" << endl;
    
    cout << "Low CON: " << lCON << " (loop";
    showlist(lCONr);
    cout << ")" << endl;
    
    cout << "Low INT: " << lINT << " (loop";
    showlist(lCONr);
    cout << ")" << endl;
    
    cout << "Low WIS: " << lWIS << " (loop";
    showlist(lWISr);
    cout << ")" << endl;
    
    cout << "Low CHA: " << lCHA << " (loop";
    showlist(lCHAr);
    cout << ")" << endl;

    
    delete STR;
    delete DEX;
    delete CON;
    delete INT;
    delete WIS;
    delete CHA;
    
}
