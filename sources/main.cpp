//******************
//
// main.cpp
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Atmosphere" part aims science lesson.
// Its goal is to explain how the atmosphere works, easily for everyone.
//
// This file contains the main part of the prototype software.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

// Include SCLS Graphic Benoit
#include "../headers/pleos_algebric_solver.h"

// Init SCLS
SCLS_INIT

int main(int argc, char* argv[]) {
    // Create mat 1
    pleos::Matrice mat_a = pleos::Matrice("P", 2, 2);
    mat_a.matrice_at(0)->set(0, 1);
    mat_a.matrice_at(0)->set(1, 3);
    mat_a.matrice_at(1)->set(0, 0);
    mat_a.matrice_at(1)->set(1, -1);
    pleos::Matrice mat_m = pleos::Matrice("M", 2, 2);
    mat_m.matrice_at(0)->set(0, 0.5);
    mat_m.matrice_at(0)->set(1, 0.75);
    mat_m.matrice_at(1)->set(0, 0);
    mat_m.matrice_at(1)->set(1, 0.25);
    pleos::Matrice mat_d = pleos::Matrice("D", 2, 2);
    mat_d.matrice_at(0)->set(0, 0.5);
    mat_d.matrice_at(0)->set(1, 0);
    mat_d.matrice_at(1)->set(0, 0);
    mat_d.matrice_at(1)->set(1, 0.25);

    scls::Formula f = scls::string_to_formula("P * M - D");
    std::vector<pleos::Matrice<scls::Fraction>> matrices;
    matrices.push_back(mat_a);
    matrices.push_back(mat_m);
    matrices.push_back(mat_d);
    pleos::Matrice<scls::Fraction> mat = f.to_field<pleos::Matrice<scls::Fraction>>(matrices);
    std::cout << "M^" << 5 << " = " << mat.to_std_string() << std::endl;

    return 0;
    pleos::__Temp_Pleos_Window window(900, 600, argv[0]);
    window.load_from_xml("assets/window.txt");

    while(window.run()) {
        window.update_event();
        window.update();

        window.render();
    } //*/

    return 0;
}
