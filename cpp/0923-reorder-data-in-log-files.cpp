class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        stable_sort(logs.begin(), logs.end(), [](const string &a, const string &b)
                    {
            stringstream sa(a),sb(b);
            string a1,b1,a2,b2;
            sa>>a1;
            sb>>b1;

            int ma=a1.size();
            int mb=b1.size();

            a2=a.substr(ma+1);
            b2=b.substr(mb+1);

            bool isadigit=isdigit(a2[0]);
            bool isbdigit=isdigit(b2[0]);
            if (isadigit && !isbdigit){
                return false;
            }else if (!isadigit && isbdigit){
                return true;
            }else if (!isadigit && !isbdigit){
                if (a2==b2){
                    return a1<b1;
                } 
                return a2<b2;
            }else{
               return false;
            } });

        return logs;
    }
};
