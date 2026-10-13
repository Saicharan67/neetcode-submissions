class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        // Step 1: Store frequencies (std::map automatically sorts keys)
        map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }

        // Step 2: Process while there are still cards left
        while (!countMap.empty()) {
            // The smallest available card is always the first element in a sorted map
            int firstCard = countMap.begin()->first;
            int groupCount = countMap.begin()->second; // How many times this card appears

            // Step 3: Check and form the group of size groupSize
            for (int i = 0; i < groupSize; i++) {
                int currentCard = firstCard + i;

                // If the consecutive card doesn't exist, or we don't have enough of them, it's invalid
                if (countMap.find(currentCard) == countMap.end() || countMap[currentCard] < groupCount) {
                    return false;
                }

                // Subtract the frequency
                countMap[currentCard] -= groupCount;

                // Clean up the map if the count drops to 0
                if (countMap[currentCard] == 0) {
                    countMap.erase(currentCard);
                }
            }
        }

        return true;
    }
};
