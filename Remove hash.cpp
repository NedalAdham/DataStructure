string hashre (string lol)
{
    string sub ,sub2 ,all;
    for (int i = 0; i < lol.size(); ++i)
    {
        int s , e;
        int flag =  0;
        if (lol[i] == '/' and lol[i+1] == '*')
        {
            for (int j = i+1; j <lol.size() ; ++j)
            {
                
                if(lol [j] == '*' and lol[j+1] == '/')
                {
                    e = j+1 ;
                    s = i ;
                    sub = lol .substr(0, s);
                    sub2 = lol .substr(e+1 , lol.size());
                    lol = sub + sub2 ;
                    flag = 1 ; 
                    //cout<<lol<<endl;
                }
                /*/
                else
                {
                    sub  = lol . substr(0,i) ;
                    lol = sub ;
                }
                 /*/
            }
        }
    }
    return lol ;
}