class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double kelvin = celsius + 273.15;
        ans.push_back(kelvin);
        double fahn = (celsius*1.80) + 32.00;
        ans.push_back(fahn);
        return ans;
    }
};