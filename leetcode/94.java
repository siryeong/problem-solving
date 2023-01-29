import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> answer = new ArrayList<>();

        for(int i = 1; i < s.length(); i++) {
            for(int j = i+1; j < s.length(); j++) {
                for(int k = j+1; k < s.length(); k++) {
                    if(!IPNumber.isIPNumber(s.substring(0, i))
                        || !IPNumber.isIPNumber(s.substring(i, j))
                        || !IPNumber.isIPNumber(s.substring(j, k))
                        || !IPNumber.isIPNumber(s.substring(k)))
                        continue;

                    IPAddress address = new IPAddress(
                            new IPNumber(s.substring(0, i)),
                            new IPNumber(s.substring(i, j)),
                            new IPNumber(s.substring(j, k)),
                            new IPNumber(s.substring(k))
                    );

                    answer.add(address.toString());
                }
            }
        }

        return answer;
    }


    class IPNumber {
        private final String number;

        public IPNumber (String number) {
            this.number = number;
        }

        public String getNumber() {
            return number;
        }

        public static boolean isIPNumber(String number) {
            if(number.length() > 3)
                return false;

            if(Integer.parseInt(number) > 255)
                return false;

            if(number.length() > 1 && number.charAt(0) == '0')
                return false;

            return true;
        }
    }

    class IPAddress {
        private final IPNumber[] ipNumbers;

        public IPAddress (IPNumber... ipNumbers) {
            if(ipNumbers.length < 4)
                throw new RuntimeException("invalid IP Numbers");
            this.ipNumbers = ipNumbers;
        }

        @Override
        public String toString() {
            return ipNumbers[0].getNumber() + "."
                    + ipNumbers[1].getNumber() + "."
                    + ipNumbers[2].getNumber() + "."
                    + ipNumbers[3].getNumber();
        }
    }
}