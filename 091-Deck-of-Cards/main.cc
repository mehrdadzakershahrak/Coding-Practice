// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <random>
#include <chrono>
#include <utility>
#include <type_traits>

using namespace std;

enum Suit { Clubs, Diamonds, Hearts, Spades};

class PlayingCard {
    protected:
        int rank;
        Suit suit;

    public:
        PlayingCard(int rank, Suit suit) {
            if (rank < 1 || rank > 13) {
                throw runtime_error("invalid rank for Playing Card");
            }
            this->rank = rank;
            this->suit = suit;
        }
        int getRank() const { return rank;}
        int getSuit() const { return suit;}

        string toString() const {
            string s;
            switch (suit) {
                case Suit::Clubs:       s = "C"; break;
                case Suit::Diamonds:    s = "D"; break;
                case Suit::Hearts:      s = "H"; break;
                case Suit::Spades:      s = "S"; break;
                default:                s = "?"; break;
            }
            return s + to_string(rank);
        }
};

template<typename Card>
class StandardDeck {
    static_assert(is_base_of<PlayingCard, Card>::value, "Card must be a subclass of PlayingCard");
    protected:
        vector<Card> deck;

    public:
        StandardDeck() {
            vector<Suit> suits = { Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades};
            for (Suit s : suits) {
                for (int r = 1; r <= 13; r++) {
                    Card c(r, s);
                    deck.push_back(c);
                }
            }
        }

        bool empty() const { return deck.empty(); }

        Card draw() {
            Card c = deck.back();
            deck.pop_back();
            return c;
        }

        void shuffle(unsigned seed) {
            default_random_engine g(seed);
            for (int i = deck.size(); i > 0; i--) {
                uniform_int_distribution<int> dist (0,i);
                int j = dist(g);
                swap(deck[i], deck[j]);
            }
        }
};

int main()
{
    StandardDeck<PlayingCard> deck;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    deck.shuffle(seed);

    while (!deck.empty()) {
        auto Card = deck.draw();
        cout << Card.toString() << "\n";
    }
    return 0;
}
