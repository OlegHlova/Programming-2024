// Task ith Brigades and their information 
#include <iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;

struct Material {
    string name;
    double volume;
    double cost;
};

struct Brigade {
    int id;
    string brigadier;
    list<Material> materials;
};

// Sorting brigades by ID in ascending order
struct BrigadeComparator {
    bool operator()(const Brigade& b1, const Brigade& b2) const {
        return b1.id < b2.id;
    }
};

list<Brigade> brigades;
map<string, Material> materials;

void readDataFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + filename);
    }

    int id;
    string brigadier;
    string materialName;
    double volume;
    double cost;

    Brigade brigade;

    while (file >> id >> brigadier >> materialName >> volume >> cost) {

        if (brigade.id != id) {

            // Add the previous brigade to the our list
            if (brigade.id != 0) {
                brigades.push_back(brigade);
            }

            // Start a new brigade !
            brigade.id = id;
            brigade.brigadier = brigadier;
            brigade.materials.clear();
        }

        // Add the material to the brigade
        brigade.materials.push_back({ materialName, volume, cost });

        // Add the material to the list of materials
        if (materials.count(materialName) == 0) {
            materials[materialName] = { materialName, volume, cost };
        }
        else {
            materials[materialName].volume += volume;
            materials[materialName].cost += cost;
        }
    }

    // Add the last brigade to the list
    if (brigade.id != 0) {
        brigades.push_back(brigade);
    }

    file.close();
}

void printBrigades(const string& filename) {
    ofstream outFile(filename);

    // Sort brigades by ID in ascending order
    brigades.sort(BrigadeComparator());

    for (const auto& brigade : brigades) {
        outFile << "Brigade ID: " << brigade.id << endl;
        outFile << "Brigadier: " << brigade.brigadier << endl;

        double totalVolume = 0;
        double totalCost = 0;

        for (const auto& material : brigade.materials) {
            outFile << "- " << material.name << ": " << material.volume << " m3, " << material.cost << " UAH" << endl;
            totalVolume += material.volume;
            totalCost += material.cost;
        }

        outFile << "Total: " << totalVolume << " m3, " << totalCost << " UAH" << endl;
        outFile << endl;
    }

    outFile.close();
}

void printMaterials(const string& filename) {
    ofstream outFile(filename);

    for (const auto& material : materials) {
        outFile << "Material: " << material.second.name << endl;
        outFile << "Total volume: " << material.second.volume << endl;
        outFile << "Total cost: " << material.second.cost << endl;
        outFile << endl;
    }
    outFile.close();
}
int main() {
    try {
        readDataFromFile("input.txt");
        printBrigades("brigades.txt");
        printMaterials("materials.txt");
    }
    catch (const exception& e) {
        cout << "Error " << e.what() << endl;
        return 1;
    }

    return 0;
}

