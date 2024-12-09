#include "ChiffrementCombine.h"

ChiffrementCombine::ChiffrementCombine() = default;

string ChiffrementCombine::chiffrer(const string& texte) {
    return chiffrementXOR.chiffrer(chiffrementCesar.chiffrer(texte));  // Chiffrement XOR puis César
}

string ChiffrementCombine::dechiffrer(const string& texte) {
    return chiffrementCesar.dechiffrer(chiffrementXOR.dechiffrer(texte));  // Déchiffrement César puis XOR
}
