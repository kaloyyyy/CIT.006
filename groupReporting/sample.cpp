#include <iostream>
#include<cmath>
using namespace std;


void aashto() {
    //declare variables for the input
    int sieve10, sieve40, sieve200, liquidL, plasticI;
    double GI;
    cout << "input sieve no.200\n";
    cin >> sieve200;
    if (sieve200 > 35) {
        cout << "Silt\n";
        cout << "input liquid limit\n";
        cin >> liquidL;
        cout << "input Plasticity Index\n";
        cin >> plasticI;
        GI = round((sieve200 - 35) * (0.2 + (0.005 * (liquidL - 40))) + 0.01 * (sieve200 - 15) * (plasticI - 10));
        if (liquidL > 40) {
            if (plasticI < liquidL - 30) {
                cout << "A-7-5 and GI is = " << GI << endl;
            } else if (plasticI > liquidL - 30) {
                cout << "A-7-6 and GI is = " << GI << endl;
            } else {
                cout << "A-5 and GI is = " << GI << endl;
            }

        } else {
            if (plasticI > 10) {
                //A-6
                cout << "A-6 and GI is = " << GI << endl;
            } else {
                cout << "A-4 and GI is = " << GI << endl;
            }
        }
    } else if (sieve200 > 25) {
        cout << "input liquid limit\n";
        cin >> liquidL;
        cout << "input Plasticity Index\n";
        cin >> plasticI;
        GI = round(0.01 * (sieve200 - 15) * (plasticI - 10));
        if (liquidL > 40) {
            if (plasticI > 10) {
                //A-2-7
                cout << "A-2-7 and GI is = " << GI << endl;
            } else {
                //A-2-5
                cout << "A-2-5\n";
            }
        } else {
            if (plasticI > 10) {
                //A-2-6
                cout << "A-2-6 and GI is = " << GI << endl;
            } else {
                //A-2-4
                cout << "A-2-4\n";
            }
        }

    } else {
        cout << "input Plasticity Index\n";
        cin >> plasticI;
        cout << "enter sieve no. 40\n";
        cin >> sieve40;
        cout << "enter sieve no.10 \n";
        cin >> sieve10;
        if (plasticI > 0) {
            if (sieve200 > 15) {
                cout << "A-1-b\n";
            } else if (sieve200 < 15) { cout << "A-1-a\n"; }
        } else {
            cout << "A-3\n";
        }
    }
}

string cuccCompare(int cuCompare, double cu, double cc, bool isGravel) {
    if (cu >= cuCompare && (1 <= cc || cc <= 3)) {
        // GW or SW
        if (isGravel) {
            return "GW";
        } else {
            return "SW";
        }
    } else {
        //GP or SP
        if (isGravel) {
            return "GP";
        } else {
            return "SP";
        }
    }
}

string plasticCompare(double PI, bool isGravel) {
    if (PI < 4) {
        //GM or SM
        if (isGravel) {
            return "GM";
        } else {
            return "SM";
        }
    } else if (PI > 7) {
        //GC or SC
        if (isGravel) {
            return "GC";
        } else {
            return "SC";
        }
    } else {
        if (isGravel) {
            return "GC-GM";
        } else {
            return "SC-SM";
        }
    }
}

string cucc(int cuCompare, bool isGravel) {
    char choice;
    double cu, cc;
    string groupSymbol;
    cout << "what are the given\n";
    cout << "a. CU, CC    b. D-values\n";
    cin >> choice;
    switch (choice) {
        case 'a':
            cout << "enter cu\n";
            cin >> cu;
            cout << "enter cc\n";
            cin >> cc;
            groupSymbol = cuccCompare(cuCompare, cu, cc, isGravel);
            break;

        case 'b':
            //input D values
            //solve cu cc from d value
            double d10, d30, d60;
            cout << "input D10 \n";
            cin >> d10;
            cout << "input D30 \n";
            cin >> d30;
            cout << "input D60 \n";
            cin >> d60;
            cu = (d60 / d10);
            cc = (d30 * d30) / (d10 * d60);
            groupSymbol = cuccCompare(cuCompare, cu, cc, isGravel);
            break;

        default:
            break;
    }
    return groupSymbol;
}


string plasticLiquid(bool isGravel) {
    char choice;
    double PI, PL, LL;
    string groupSymbol;
    cout << "what are the given\n";
    cout << "a.PI   b. PL & LL\n";
    cin >> choice;
    switch (choice) {
        case 'a':
            cout << "enter PI\n";
            cin >> PI;
            groupSymbol = plasticCompare(PI, isGravel);
            break;

        case 'b':
            cout << "enter PL\n";
            cin >> PL;
            cout << "enter LL\n";
            cin >> LL;
            PI = LL - PL;
            groupSymbol = plasticCompare(PI, isGravel);
            break;

        default:
            break;
    }
    return groupSymbol;
}

void gravelSand(int s200, int s4, int cuCompare, bool isGravel) {
    string groupSymbol;
    string groupName;
    string wellG = "well-graded";
    string poorlyG = "poorly graded";
    if (s200 < 5) {
        groupSymbol = cucc(cuCompare, isGravel);
    } else if (s200 > 12) {
        groupSymbol = plasticLiquid(isGravel);
    } else {
        //in between
        groupSymbol = cucc(cuCompare, isGravel);
        groupSymbol.append("-" + plasticLiquid(isGravel));

    } // continue
    if (groupSymbol == "GW") {
        groupName = wellG + " gravel";
        if (s4 >= 15) {
            groupName.append(" with sand");
        }
    } else if (groupSymbol == "GP") {
        groupName = poorlyG + " gravel";
        if (s4 >= 15) {
            groupName.append(" with sand");
        }
    } else if (groupSymbol == "GW-GM") {
        groupName = wellG + " gravel with silt ";
        if (s4 >= 15) {
            groupName.append(" and sand ");
        }
    } else if (groupSymbol == "GW-GC") {
        groupName = wellG + " gravel with clay (or silty clay)";
        if (s4 >= 15) {
            groupName = " gravel with clay and sand (or silty clay and sand)";
        }
    } else if (groupSymbol == "GP-GM") {
        groupName = poorlyG + " gravel with silt";
        if (s4 >= 15) {
            groupName.append(" gravel with silt and sand");
        }
    } else if (groupSymbol == "GP-GC") {
        groupName = poorlyG + " gravel with clay (or silty clay)";
        if (s4 >= 15) {
            groupName.append(" gravel with clay and sand (or silty clay and sand)");
        }
    } else if (groupSymbol == "GM") {
        groupName = "silty gravel";
        if (s4 >= 15) {
            groupName = " silty gravel with sand";
        }
    } else if (groupSymbol == "GC") {
        groupName = "clayey gravel";
        if (s4 >= 15) {
            groupName = "clayey gravel with sand";
        }
    } else if (groupSymbol == "GC") {
        groupName = "clayey gravel";
        if (s4 >= 15) {
            groupName = "clayey gravel with sand";
        }
    } else if (groupSymbol == "GC-GM") {
        groupName = "silty clayey gravel";
        if (s4 >= 15) {
            groupName = "silty clayey gravel with sand";
        }
    } else if (groupSymbol == "SW") {
        groupName = wellG + " sand";
        if (s4 >= 15) {
            groupName.append(" sand with gravel");
        }
    } else if (groupSymbol == "SP") {
        groupName = poorlyG + " sand";
        if (s4 >= 15) {
            groupName.append(" sand with gravel");
        }
    } else if (groupSymbol == "SW-SM") {
        groupName = wellG + " sand with silt";
        if (s4 >= 15) {
            groupName.append(" sand with silt and gravel");
        }
    } else if (groupSymbol == "SW-SC") {
        groupName = wellG + " sand with clay(or silty clay)";
        if (s4 >= 15) {
            groupName.append(" sand with clay and gravel(or silty clay and gravel)");
        }
    } else if (groupSymbol == "SP-SM") {
        groupName = poorlyG + " sand with silt";
        if (s4 >= 15) {
            groupName = poorlyG + " sand with silt and gravel";
        }
    } else if (groupSymbol == "SP-SC") {
        groupName = poorlyG + " sand with clay (or silty clay)";
        if (s4 >= 15) {
            groupName = poorlyG + " sand with clay and gravel ( or silty clay and gravel";
        }
    } else if (groupSymbol == "SM") {
        groupName = "silty sand";
        if (s4 >= 15) {
            groupName = "silty sand with gravel";
        }
    } else if (groupSymbol == "SC") {
        groupName = "clayey sand";
        if (s4 >= 15) {
            groupName = "clayey sand with gravel";
        }
    } else if (groupSymbol == "SC-SM") {
        groupName = "silty clayey sand";
        if (s4 >= 15) {
            groupName = "silty clayey sand with gravel";
        }
    }
    cout << "group symbol: " << groupSymbol << endl;
    cout << "group name: " << groupName << endl;

}

void fineGroupName(int s200, int s4, double plasticIndex, const string &gName) {
    double sand;
    sand = 100 - s200;
    if (s200 < 30) {
        if (s200 < 15) {
            cout << gName << "\n";
        } else {
            if (s200 >= s4) {
                cout << gName + " with sand\n";
            } else {
                cout << gName + " with gravel\n";
            }
        }
    } else {
        if (s200 >= s4) {
            if (s4 < 15) {
                cout << "Sandy " << gName << "\n";
            } else {
                cout << "Sandy " << gName << " with gravel\n";
            }
        } else {
            if (s4 < 15) {
                cout << "Gravelly " << gName << "\n";
            } else {
                cout << "Gravelly " << gName << " with sand\n";
            }
        }
    }
}

void uscs() {
    int s200, s4;
    double aLine;
    cout << "input percent passing in sieve no. 200 \n";
    cin >> s200;
    cout << "input percent passing in sieve no.4 \n";
    cin >> s4;
    char selection;
    if (s200 < 50) {
        //coarse
        if (s4 < 50) {
            //gravel
            gravelSand(s200, s4, 4, true);
        } else {
            //sand
            gravelSand(s200, s4, 6, false);
        }
    } else {
        //fine grained
        double LL;
        bool isOrg;
        char choice;
        cout << "a. organic  b. inorganic\n";
        cin >> choice;
        if (choice == 'a') {
            isOrg = true;
        } else {
            isOrg = false;
        }
        cout << "enter LL\n";
        cin >> LL;
        double plasticIndex;
        cout << "enter plastic index\n";
        cin >> plasticIndex;
        aLine = 0.73 * (LL - 20);
        if (!isOrg) {
            if (LL < 50) {
                if (aLine < plasticIndex && plasticIndex > 7) {
                    cout << "CL\n";
                    fineGroupName(s200, s4, plasticIndex, "Lean clay");
                } else if (aLine > plasticIndex && plasticIndex > 4) {
                    cout << "ML\n";
                    fineGroupName(s200, s4, plasticIndex, "Silt");
                } else if (plasticIndex >= 4 && plasticIndex <= 7) {
                    cout << "CL-ML\n";
                    fineGroupName(s200, s4, plasticIndex, "Silty clay");
                }

            } else {
                if (aLine < plasticIndex) {
                    cout << "CH\n";
                    fineGroupName(s200, s4, plasticIndex, "Fat clay");
                } else if (aLine > plasticIndex) {
                    cout << "MH\n";
                    fineGroupName(s200, s4, plasticIndex, "Elastic silt");
                }
            }
        } else {
            if (LL < 50) {
                cout << "OL\n";
                if (plasticIndex >= 4 && aLine <= plasticIndex) {
                    fineGroupName(s200, s4, plasticIndex, "Organic clay");
                } else {
                    fineGroupName(s200, s4, plasticIndex, "Organic silt");
                }
            } else {
                cout << "OH\n";
                if (aLine < plasticIndex) {
                    fineGroupName(s200, s4, plasticIndex, "Organic clay");
                } else {
                    fineGroupName(s200, s4, plasticIndex, "Organic silt");
                }
            }
        }
    }
}

//main driver and main menu
int main() {
    char choice;
    do {
        cout << "a. AASHTO   b. USCS\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                aashto();
                break;
            case 'b':
                uscs();
                break;
            default:
                cout << "invalid choice\n";
                break;
        }
    } while (choice != 'x');
}