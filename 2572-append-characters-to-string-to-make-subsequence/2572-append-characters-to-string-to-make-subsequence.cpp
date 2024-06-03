class Solution {
public:

/*

Bujji:- Bhairava aaj ka leetcode ka POTD dekha, samjh nhi aa rha.
Bhairava:- Arey yar abhi abhi to nind se utha hu, chal aa dekhate hai.

Bujji:- Ruk mai tereko ko que samjahti hu, esme hame do string given hai s and t 
        hame ye btana hai ki aakhir hme s ke end me kitne character add kre ki
        t subsquence ban jaye s ka, bhairava subsquence to pta hi hoga.

Bhairava:- be like aayen....ye kya hota hai.
Bujji:- Gusse me aake and 30min tak unki ladai chalti hai, phir dono que ko solve karna 
        start krte hai

Bhairava:- Two pointer lga dete hai (simple to hai ?)
Bujji:- aise kaise, why ? reason kya hai.

Bhairava:- dekho bujji hame t ko s ka subsquence banana hai and and hme minimum 
            character puchcha hai ese bnane ke liye thik n.
            To dekho pehle ham jitna common bna skte hai, utna bna lete hai, baki 
            jo bachega vo end me add kr denge

Bujji:- bhairava simple rakho, complicate nhi karne ka.

Bhairava:- t s ka subsquence hai, yani ham pehle s and t me sath sath traverse krte hai
            and and jo maximum t ka part s me aa gya good and jo bachca, use last me add
            kr denge
Bujji:- samjh gyi bhairava, example se samjhao, tumhe pta hi hai mai kitni smart hu
        prove krke dikhao mujhe

Bhairava:- s=aab t=abc
        suppose bujji tum t pe khadi ho mai s pe, thik agr ham dono ka character mila to
        ham dono, tata karnege aur aage badenge agr nhi mila to sirf mai aage badhunga
Bujji:- rule to thik hai, lekin na match krne pe tum kyu badhoge ?

Bhairava:- Dekho bujji, t s ka subsquence hai, yani t ke character ko chhod nhi skte hai
            esiliye ham squence me matching maximum character ko khojna hai
            esiliye jab match to dono aage badhenge kyuki vo character to mil gya n 
            lekin jab match nhi huaa yani vo character nhi mila, then mai aage badhunga 
            aur tumse matching character khojunga, thik hai bujji?

Bujji:- thik hai thik hai, samjh gyi, jayda smart mat ban.

Bhairva:- bas aise hi traverse karenge aur aakhiri me tum ye dekh lena ki, jitni length
            hai t ki, tumne utna cover kiya ya nhi, agr nhi to remaining chacater answer 
            hi answer hoga, use hi end me add karna hoga

Bujji:- s=aab, t=abc , bhairva esme kya s me kaun sa a choose kru, usse koi fark padega ?
Bhairava:- nahi bujji koi fark nhi padega, ek baar dhyan se socho.


Bujji:- chal bhairava mai code krne ja rhi
Bhairava:- bujji agr minimum answer nhi dene ko hota to kya krti
Bujji:- simple bhairva t ki size return kr deti, yani ki sare character ko add kar dungi
        t wale string k, kyuki minimum to puchcha nhi hota

Bhairava:- Ye to bahot smart ho gayi hai, chalta hu sone..


Tum log knha ja rhe code kro chup chaap


Milte hai bujji aur bhairva ki agli ladai me
*/

    int appendCharacters(string s, string t) {
        // bujji aur bhairva khade ho gye dono string ke start me
        int bhairva=0;
        int bujji=0; 

        int n=s.size();
        int m=t.size(); 

        while(bhairva<n && bujji<m){
            // agr match huaa
            if(s[bhairva]==t[bujji]){
                // dono aage badhenge
                // next character ki khoj me
                bhairva++;bujji++;
            }else{
                // nhi match, bhairva aage jayega
                // dekhane ki current bujji ka character s me hai bhi ya nhi
                bhairva++;
            }
        }

        // s=aab
        // t=abc

        // esme t me i=1 tak match hoga then i=2 pe move kr jayega but kuchch
        // matching nhi milega to 1 character add krna hoga s me 
        // kaise pta chala? jnha pe tha, jo match nhi huaa usko size se ghata diya

        // 3 - 2 => 1 (answere es case me)

        // ye kaise ???
        return m-bujji;
    }
};