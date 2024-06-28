#include <iostream>
using namespace std;

int main() {
    int setAmount, i;
    double aResult = 0, bResult = 0, cResult = 0, dResult = 0, eResult = 0, aDraws = 0, bDraws = 0, cDraws = 0, dDraws = 0, eDraws = 0, aSets = 0, bSets = 0, cSets = 0, dSets = 0, eSets = 0;
    
    char fPlayer, sPlayer;
    int fDiceO, fDiceT, fDiceTH, fDiceF;
    int sDiceO, sDiceT, sDiceTH, sDiceF;
    
    i = 1;
    cin >> setAmount;
    if (setAmount != 0) {
        do {
            bool set = 0;
            
            cin >> fPlayer >> fDiceO >> fDiceT >> fDiceTH >> fDiceF;
            cin >> sPlayer >> sDiceO >> sDiceT >> sDiceTH >> sDiceF;
            if (fPlayer != sPlayer) {
                
                // four same results
                bool fEqual = 0, sEqual = 0;
                if (!set) {
                    if (fDiceO == fDiceT && fDiceO == fDiceTH && fDiceO == fDiceF) fEqual = 1;
                    if (sDiceO == sDiceT && sDiceO == sDiceTH && sDiceO == sDiceF) sEqual = 1;
                    
                    if (fEqual && !sEqual) {
                        if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') aSets = aSets + 1;
                        if(sPlayer == 'b') bSets = bSets + 1;
                        if(sPlayer == 'c') cSets = cSets + 1;
                        if(sPlayer == 'd') dSets = dSets + 1;
                        if(sPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else if (!fEqual && sEqual) {
                        if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(fPlayer == 'a') aSets = aSets + 1;
                        if(fPlayer == 'b') bSets = bSets + 1;
                        if(fPlayer == 'c') cSets = cSets + 1;
                        if(fPlayer == 'd') dSets = dSets + 1;
                        if(fPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    }
                }
                
                // not equal results
                bool fNotEqual = 0, sNotEqual = 0;
                if (!set && !fEqual && !sEqual) {
                    if (fDiceO != fDiceT && fDiceO != fDiceTH && fDiceO != fDiceF && fDiceT != fDiceTH && fDiceT != fDiceF && fDiceTH != fDiceF) fNotEqual = 1;
                    if (sDiceO != sDiceT && sDiceO != sDiceTH && sDiceO != sDiceF && sDiceT != sDiceTH && sDiceT != sDiceF && sDiceTH != sDiceF) sNotEqual = 1;
                    
                    if (fNotEqual || sNotEqual) {
                        if (fNotEqual && !sNotEqual) {
                            if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(sPlayer == 'a') aSets = aSets + 1;
                            if(sPlayer == 'b') bSets = bSets + 1;
                            if(sPlayer == 'c') cSets = cSets + 1;
                            if(sPlayer == 'd') dSets = dSets + 1;
                            if(sPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        } else if (!fNotEqual && sNotEqual) {
                            if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(fPlayer == 'a') aSets = aSets + 1;
                            if(fPlayer == 'b') bSets = bSets + 1;
                            if(fPlayer == 'c') cSets = cSets + 1;
                            if(fPlayer == 'd') dSets = dSets + 1;
                            if(fPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        } else {
                            if(fPlayer == 'a') { aDraws = aDraws + 1; aSets = aSets + 1; }
                            if(fPlayer == 'b') { bDraws = bDraws + 1; bSets = bSets + 1; }
                            if(fPlayer == 'c') { cDraws = cDraws + 1; cSets = cSets + 1; }
                            if(fPlayer == 'd') { dDraws = dDraws + 1; dSets = dSets + 1; }
                            if(fPlayer == 'e') { eDraws = eDraws + 1; eSets = eSets + 1; }
                            
                            if(sPlayer == 'a') { aDraws = aDraws + 1; aSets = aSets + 1; }
                            if(sPlayer == 'b') { bDraws = bDraws + 1; bSets = bSets + 1; }
                            if(sPlayer == 'c') { cDraws = cDraws + 1; cSets = cSets + 1; }
                            if(sPlayer == 'd') { dDraws = dDraws + 1; dSets = dSets + 1; }
                            if(sPlayer == 'e') { eDraws = eDraws + 1; eSets = eSets + 1; }
                            set = 1;
                        }
                    }
                }
                
                
                // three equal results
                bool fThreeEqual = 0, sThreeEqual = 0;
                if (!set && !fEqual && !sEqual && !fNotEqual && !sNotEqual) {
                    if (((fDiceO == fDiceT) && (fDiceO == fDiceTH)) || ((fDiceO == fDiceT) && (fDiceO == fDiceF)) || ((fDiceO == fDiceTH) && (fDiceO == fDiceF)) || ((fDiceT == fDiceTH) && (fDiceT == fDiceF))) fThreeEqual = 1;
                    if (((sDiceO == sDiceT) && (sDiceO == sDiceTH)) || ((sDiceO == sDiceT) && (sDiceO == sDiceF)) || ((sDiceO == sDiceTH) && (sDiceO == sDiceF)) || ((sDiceT == sDiceTH) && (sDiceT == sDiceF))) sThreeEqual = 1;
                    
                    if (fThreeEqual && !sThreeEqual) {
                        if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') aSets = aSets + 1;
                        if(sPlayer == 'b') bSets = bSets + 1;
                        if(sPlayer == 'c') cSets = cSets + 1;
                        if(sPlayer == 'd') dSets = dSets + 1;
                        if(sPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else if (!fThreeEqual && sThreeEqual) {
                        if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(fPlayer == 'a') aSets = aSets + 1;
                        if(fPlayer == 'b') bSets = bSets + 1;
                        if(fPlayer == 'c') cSets = cSets + 1;
                        if(fPlayer == 'd') dSets = dSets + 1;
                        if(fPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else {
                        int fThreeSum = 0, sThreeSum = 0;
                        
                        if (fDiceO == fDiceT && fDiceO == fDiceTH) fThreeSum = fDiceO + fDiceT + fDiceTH;
                        else if (fDiceO == fDiceT && fDiceO == fDiceF) fThreeSum = fDiceO + fDiceT + fDiceF;
                        else if (fDiceO == fDiceTH && fDiceO == fDiceF) fThreeSum = fDiceO + fDiceTH + fDiceF;
                        else if (fDiceT == fDiceTH && fDiceT == fDiceF) fThreeSum = fDiceT + fDiceTH + fDiceF;
                        
                        if (sDiceO == sDiceT && sDiceO == sDiceTH) sThreeSum = sDiceO + sDiceT + sDiceTH;
                        else if (sDiceO == sDiceT && sDiceO == sDiceF) sThreeSum = sDiceO + sDiceT + sDiceF;
                        else if (sDiceO == sDiceTH && sDiceO == sDiceF) sThreeSum = sDiceO + sDiceTH + sDiceF;
                        else if (sDiceT == sDiceTH && sDiceT == sDiceF) sThreeSum = sDiceT + sDiceTH + sDiceF;
                        
                        if (fThreeSum > sThreeSum) {
                            if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(sPlayer == 'a') aSets = aSets + 1;
                            if(sPlayer == 'b') bSets = bSets + 1;
                            if(sPlayer == 'c') cSets = cSets + 1;
                            if(sPlayer == 'd') dSets = dSets + 1;
                            if(sPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        } else if (fThreeSum < sThreeSum) {
                            if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(fPlayer == 'a') aSets = aSets + 1;
                            if(fPlayer == 'b') bSets = bSets + 1;
                            if(fPlayer == 'c') cSets = cSets + 1;
                            if(fPlayer == 'd') dSets = dSets + 1;
                            if(fPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        }
                    }
                }
                
                
                // Two different pairs
                bool fTwoPairs = 0, sTwoPairs = 0;
                if (!set && !fEqual && !sEqual && !fNotEqual && !sNotEqual && !fThreeEqual && !sThreeEqual) {
                    if ((fDiceO == fDiceT || fDiceO == fDiceTH || fDiceO == fDiceF) && ((fDiceT != fDiceO && (fDiceT == fDiceTH || fDiceT == fDiceF)) || (fDiceTH != fDiceO && (fDiceTH == fDiceF)))) fTwoPairs = 1;
                    if ((sDiceO == sDiceT || sDiceO == sDiceTH || sDiceO == sDiceF) && ((sDiceT != sDiceO && (sDiceT == sDiceTH || sDiceT == sDiceF)) || (sDiceTH != sDiceO && (sDiceTH == sDiceF)))) sTwoPairs = 1;
                    
                    if (fTwoPairs && !sTwoPairs) {
                        if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') aSets = aSets + 1;
                        if(sPlayer == 'b') bSets = bSets + 1;
                        if(sPlayer == 'c') cSets = cSets + 1;
                        if(sPlayer == 'd') dSets = dSets + 1;
                        if(sPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else if (!fTwoPairs && sTwoPairs) {
                        if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(fPlayer == 'a') aSets = aSets + 1;
                        if(fPlayer == 'b') bSets = bSets + 1;
                        if(fPlayer == 'c') cSets = cSets + 1;
                        if(fPlayer == 'd') dSets = dSets + 1;
                        if(fPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else {
                        int fTwoSum = 0, sTwoSum = 0;
                        if (fDiceO == fDiceT && fDiceO + fDiceT > fTwoSum) fTwoSum = fDiceO + fDiceT;
                        if (fDiceO == fDiceTH && fDiceO + fDiceTH > fTwoSum) fTwoSum = fDiceO + fDiceTH;
                        if (fDiceO == fDiceF && fDiceO + fDiceF > fTwoSum) fTwoSum = fDiceO + fDiceF;
                        if (fDiceT == fDiceTH && fDiceT + fDiceTH > fTwoSum) fTwoSum = fDiceT + fDiceTH;
                        if (fDiceT == fDiceF && fDiceT + fDiceF > fTwoSum) fTwoSum = fDiceT + fDiceF;
                        if (fDiceTH == fDiceF && fDiceTH + fDiceF > fTwoSum) fTwoSum = fDiceTH + fDiceF;
                        
                        if (sDiceO == sDiceT && sDiceO + sDiceT > sTwoSum) sTwoSum = sDiceO + sDiceT;
                        if (sDiceO == sDiceTH && sDiceO + sDiceTH > sTwoSum) sTwoSum = sDiceO + sDiceTH;
                        if (sDiceO == sDiceF && sDiceO + sDiceF > sTwoSum) sTwoSum = sDiceO + sDiceF;
                        if (sDiceT == sDiceTH && sDiceT + sDiceTH > sTwoSum) sTwoSum = sDiceT + sDiceTH;
                        if (sDiceT == sDiceF && sDiceT + sDiceF > sTwoSum) sTwoSum = sDiceT + sDiceF;
                        if (sDiceTH == sDiceF && sDiceTH + sDiceF > sTwoSum) sTwoSum = sDiceTH + sDiceF;
                        
                        if (fTwoSum > sTwoSum) {
                            if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(sPlayer == 'a') aSets = aSets + 1;
                            if(sPlayer == 'b') bSets = bSets + 1;
                            if(sPlayer == 'c') cSets = cSets + 1;
                            if(sPlayer == 'd') dSets = dSets + 1;
                            if(sPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        } else if (fTwoSum < sTwoSum) {
                            if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(fPlayer == 'a') aSets = aSets + 1;
                            if(fPlayer == 'b') bSets = bSets + 1;
                            if(fPlayer == 'c') cSets = cSets + 1;
                            if(fPlayer == 'd') dSets = dSets + 1;
                            if(fPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        }
                    }
                }
                
                // two equal results (pair)
                bool fPair = 0, sPair = 0;
                if (!set && !fEqual && !sEqual && !fNotEqual && !sNotEqual && !fThreeEqual && !sThreeEqual && !fTwoPairs && !sTwoPairs) {
                    if ((fDiceO == fDiceT) || (fDiceO == fDiceTH) || (fDiceO == fDiceF) || (fDiceT == fDiceTH) || (fDiceT == fDiceF) || (fDiceTH == fDiceF)) fPair = 1;
                    if ((sDiceO == sDiceT) || (sDiceO == sDiceTH) || (sDiceO == sDiceF) || (sDiceT == sDiceTH) || (sDiceT == sDiceF) || (sDiceTH == sDiceF)) sPair = 1;
                    
                    if (fPair && !sPair) {
                        if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') aSets = aSets + 1;
                        if(sPlayer == 'b') bSets = bSets + 1;
                        if(sPlayer == 'c') cSets = cSets + 1;
                        if(sPlayer == 'd') dSets = dSets + 1;
                        if(sPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else if (!fPair && sPair) {
                        if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(fPlayer == 'a') aSets = aSets + 1;
                        if(fPlayer == 'b') bSets = bSets + 1;
                        if(fPlayer == 'c') cSets = cSets + 1;
                        if(fPlayer == 'd') dSets = dSets + 1;
                        if(fPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else {
                        int fTwoSum = 0, sTwoSum = 0;
                        if (fDiceO == fDiceT) fTwoSum = fDiceO + fDiceT;
                        else if (fDiceO == fDiceTH) fTwoSum = fDiceO + fDiceTH;
                        else if (fDiceO == fDiceF) fTwoSum = fDiceO + fDiceF;
                        else if (fDiceT == fDiceTH) fTwoSum = fDiceT + fDiceTH;
                        else if (fDiceT == fDiceF) fTwoSum = fDiceT + fDiceF;
                        else if (fDiceTH == fDiceF) fTwoSum = fDiceTH + fDiceF;
                        
                        if (sDiceO == sDiceT) sTwoSum = sDiceO + sDiceT;
                        else if (sDiceO == sDiceTH) sTwoSum = sDiceO + sDiceTH;
                        else if (sDiceO == sDiceF) sTwoSum = sDiceO + sDiceF;
                        else if (sDiceT == sDiceTH) sTwoSum = sDiceT + sDiceTH;
                        else if (sDiceT == sDiceF) sTwoSum = sDiceT + sDiceF;
                        else if (sDiceTH == sDiceF) sTwoSum = sDiceTH + sDiceF;
                        
                        if (fTwoSum > sTwoSum) {
                            if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(sPlayer == 'a') aSets = aSets + 1;
                            if(sPlayer == 'b') bSets = bSets + 1;
                            if(sPlayer == 'c') cSets = cSets + 1;
                            if(sPlayer == 'd') dSets = dSets + 1;
                            if(sPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        } else if (fTwoSum < sTwoSum) {
                            if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                            if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                            if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                            if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                            if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                            
                            if(fPlayer == 'a') aSets = aSets + 1;
                            if(fPlayer == 'b') bSets = bSets + 1;
                            if(fPlayer == 'c') cSets = cSets + 1;
                            if(fPlayer == 'd') dSets = dSets + 1;
                            if(fPlayer == 'e') eSets = eSets + 1;
                            set = 1;
                        }
                    }
                }
                
                // other
                if (!set) {
                    int fDiceSum = fDiceO + fDiceT + fDiceTH + fDiceF;
                    int sDiceSum = sDiceO + sDiceT + sDiceTH + sDiceF;
                    
                    if (fDiceSum > sDiceSum) {
                        if(fPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') aSets = aSets + 1;
                        if(sPlayer == 'b') bSets = bSets + 1;
                        if(sPlayer == 'c') cSets = cSets + 1;
                        if(sPlayer == 'd') dSets = dSets + 1;
                        if(sPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else if (fDiceSum < sDiceSum) {
                        if(sPlayer == 'a') { aResult = aResult + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bResult = bResult + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cResult = cResult + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dResult = dResult + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eResult = eResult + 1; eSets = eSets + 1; }
                        
                        if(fPlayer == 'a') aSets = aSets + 1;
                        if(fPlayer == 'b') bSets = bSets + 1;
                        if(fPlayer == 'c') cSets = cSets + 1;
                        if(fPlayer == 'd') dSets = dSets + 1;
                        if(fPlayer == 'e') eSets = eSets + 1;
                        set = 1;
                    } else {
                        if(fPlayer == 'a') { aDraws = aDraws + 1; aSets = aSets + 1; }
                        if(fPlayer == 'b') { bDraws = bDraws + 1; bSets = bSets + 1; }
                        if(fPlayer == 'c') { cDraws = cDraws + 1; cSets = cSets + 1; }
                        if(fPlayer == 'd') { dDraws = dDraws + 1; dSets = dSets + 1; }
                        if(fPlayer == 'e') { eDraws = eDraws + 1; eSets = eSets + 1; }
                        
                        if(sPlayer == 'a') { aDraws = aDraws + 1; aSets = aSets + 1; }
                        if(sPlayer == 'b') { bDraws = bDraws + 1; bSets = bSets + 1; }
                        if(sPlayer == 'c') { cDraws = cDraws + 1; cSets = cSets + 1; }
                        if(sPlayer == 'd') { dDraws = dDraws + 1; dSets = dSets + 1; }
                        if(sPlayer == 'e') { eDraws = eDraws + 1; eSets = eSets + 1; }
                        set = 1;
                    }
                }
                
            } else {
                if(fPlayer == 'a') { aDraws = aDraws; aSets = aSets; }
                if(fPlayer == 'b') { bDraws = bDraws; bSets = bSets; }
                if(fPlayer == 'c') { cDraws = cDraws; cSets = cSets; }
                if(fPlayer == 'd') { dDraws = dDraws; dSets = dSets; }
                if(fPlayer == 'e') { eDraws = eDraws; eSets = eSets; }
            }
            i = i + 1;
        } while (i <= setAmount);
    }
    
    double aLoose = aSets - (aResult + aDraws);
    double bLoose = bSets - (bResult + bDraws);
    double cLoose = cSets - (cResult + cDraws);
    double dLoose = dSets - (dResult + dDraws);
    double eLoose = eSets - (eResult + eDraws);
    
    // player a
    if (aSets > 0) {
        cout << "gracz a" << endl;
        if (aResult > 0) cout << "    wygrane: " << (aResult / aSets) * 100 << "%" << endl      ;
        if (aDraws > 0) cout << "    remisy: " << (aDraws / aSets) * 100 << "%" << endl      ;
        if (aLoose > 0) cout << "    przegrane: " << (aLoose / aSets) * 100 << "%" << endl      ;
        if (bSets > 0 || cSets > 0 || dSets > 0 || eSets > 0) cout << endl;
    }
    
    // player b
    if (bSets > 0) {
        cout << "gracz b" << endl;
        if (bResult > 0) cout << "    wygrane: " << (bResult / bSets) * 100 << "%" << endl      ;
        if (bDraws > 0) cout << "    remisy: " << (bDraws / bSets) * 100 << "%" << endl      ;
        if (bLoose > 0) cout << "    przegrane: " << (bLoose / bSets) * 100 << "%" << endl      ;
        if (cSets > 0 || dSets > 0 || eSets > 0) cout << endl;
    }
    
    // player c
    if (cSets > 0) {
        cout << "gracz c" << endl;
        if (cResult > 0) cout << "    wygrane: " << (cResult / cSets) * 100 << "%" << endl      ;
        if (cDraws > 0) cout << "    remisy: " << (cDraws / cSets) * 100 << "%" << endl      ;
        if (cLoose > 0) cout << "    przegrane: " << (cLoose / cSets) * 100 << "%" << endl      ;
        if (dSets > 0 || eSets > 0) cout << endl;
    }
    
    // player d
    if (dSets > 0) {
        cout << "gracz d" << endl;
        if (dResult > 0) cout << "    wygrane: " << (dResult / dSets) * 100 << "%" << endl      ;
        if (dDraws > 0) cout << "    remisy: " << (dDraws / dSets) * 100 << "%" << endl      ;
        if (dLoose > 0) cout << "    przegrane: " << (dLoose / dSets) * 100 << "%" << endl      ;
        if (eSets > 0) cout << endl;
    }
    
    // player e
    if (eSets > 0) {
        cout << "gracz e" << endl;
        if (eResult > 0) cout << "    wygrane: " << (eResult / eSets) * 100 << "%" << endl      ;
        if (eDraws > 0) cout << "    remisy: " << (eDraws / eSets) * 100 << "%" << endl      ;
        if (eLoose > 0) cout << "    przegrane: " << (eLoose / eSets) * 100 << "%" << endl      ;
    }
    return 0;
}
