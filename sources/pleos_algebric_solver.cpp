//******************
//
// pleos_algebric_solver.cpp
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
// This file contains the source code of pleos_algebric_solver.h.
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

// Include pleos_algebric_solver.h
#include "../headers/pleos_algebric_solver.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Algebric_Solver_Page constructor
    Algebric_Solver_Page::Algebric_Solver_Page(scls::_Window_Advanced_Struct* window_struct, std::string name) : scls::GUI_Page(window_struct, name) {}

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        std::shared_ptr<scls::GUI_Object> to_return;

        // Check navigation
        to_return = __create_loaded_object_from_type_navigation(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Check page by page
        to_return = __create_loaded_object_from_type_complex_number(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_home(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Classic object creation
        return GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_complex_number(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_complex_number_body") {
            a_complex_number_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_complex_number_page;
        }
        else if(object_name == "algebric_solver_complex_number_simplify") {
            a_complex_number_simplify_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_simplify_button;
        }
        else if(object_name == "algebric_solver_complex_number_simplify_input") {
            a_complex_number_simplify_input = *parent->new_object<scls::GUI_Text_Input>(object_name);
            return a_complex_number_simplify_input;
        }
        else if(object_name == "algebric_solver_complex_number_simplify_result") {
            a_complex_number_simplify_result = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_simplify_result;
        }
        return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_home_body") {
            a_home_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_home_page;
        }
        return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_navigation_complex_number_button") {
            a_complex_number_navigation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_navigation_button;
        }
        else if(object_name == "algebric_solver_navigation_home_button") {
            a_home_navigation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_home_navigation_button;
        }
        return std::shared_ptr<scls::GUI_Object>();
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Check the complex number event
    void Algebric_Solver_Page::check_complex_number_events() {
        // Check if a simplification is needed
        if(a_complex_number_simplify_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // (32zi * 8x + 7)(45z * 7 + 9xi)
            scls::Polymonial polymonial = scls::string_to_polymonial(complex_number_simplify_input());
            std::cout << complex_number_simplify_input() << " = " << polymonial << std::endl;
        }
    }

    // Check the navigation event
    void Algebric_Solver_Page::check_navigation_events() {
        if(a_complex_number_navigation_button.get() != 0 && a_complex_number_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_complex_number_page();
        if(a_home_navigation_button.get() != 0 && a_home_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_home_page();
    }

    // Update the events
    void Algebric_Solver_Page::update_event() {
        GUI_Page::update_event();

        // Check the navigation event
        check_navigation_events();

        // Complex number vents
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE) check_complex_number_events();
    }

    //******************
    //
    // Handle the pages
    //
    //******************

    // Displays the complex number page
    void Algebric_Solver_Page::display_complex_number_page() {
        hide_all();
        if(a_complex_number_page.get() != 0) a_complex_number_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE);
    }

    // Displays the home page
    void Algebric_Solver_Page::display_home_page() {
        hide_all();
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_HOME_PAGE);
    }

    // Hides all the pages
    void Algebric_Solver_Page::hide_all() {
        if(a_complex_number_page.get() != 0) a_complex_number_page.get()->set_visible(false);
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(false);
    }
}
