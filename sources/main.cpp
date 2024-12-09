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
    pleos::Matrice mat_1 = pleos::Matrice(3, 2);
    mat_1.matrice_at(0)->set(0, -3);
    mat_1.matrice_at(0)->set(1, 3);
    mat_1.matrice_at(0)->set(2, -3);
    mat_1.matrice_at(1)->set(0, 3);
    mat_1.matrice_at(1)->set(1, -3);
    mat_1.matrice_at(1)->set(2, 3);
    // Create mat 2
    pleos::Matrice mat_2 = pleos::Matrice(2, 3);
    mat_2.matrice_at(0)->set(0, -7);
    mat_2.matrice_at(1)->set(0, 5);
    mat_2.matrice_at(2)->set(0, -1);
    mat_2.matrice_at(0)->set(1, -7);
    mat_2.matrice_at(1)->set(1, 5);
    mat_2.matrice_at(2)->set(1, -1);
    std::cout << "A " << mat_1.dimension().dimension_number() << " " << mat_2.dimension().dimension_number() << " " << mat_2.dimension().last_dimension() << std::endl;
    mat_1 *= mat_2;
    std::cout << mat_1.to_std_string() << " " << mat_2.dimension().dimension_number() << std::endl;

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
