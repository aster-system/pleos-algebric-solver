//******************
//
// pleos_algebric_solver.h
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
// This file contains the page of the Algebric Solver plugin.
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

#ifndef PLEOS_ALGEBRIC_SOLVER
#define PLEOS_ALGEBRIC_SOLVER

// Include SCLS Graphic Benoit
#include "../../../scls-graphic-benoit/scls_graphic.h"

// Possibles pages
#define PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE 0
#define PLEOS_ALGEBRIC_SOLVER_HOME_PAGE 1
#define PLEOS_ALGEBRIC_SOLVER_NUMBER_THEORY_PAGE 2
#define PLEOS_ALGEBRIC_SOLVER_FUNCTION_PAGE 3
#define PLEOS_ALGEBRIC_SOLVER_SEQUENCES_PAGE 4

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Algebric_Solver_Page : public scls::GUI_Page {
        // Class representating the algebric solver page for PLEOS
    public:

        // Algebric_Solver_Page constructor
        Algebric_Solver_Page(scls::_Window_Advanced_Struct* window_struct, std::string name);
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_complex_number(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_function(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_number_theory(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_sequences(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Analyse handling
        //
        //******************

        // Possible studied type
        enum Studied_Type {ST_Sequence};
        // Datas about a studied function
        struct Function_Studied {
            // Formula of the function
            scls::Formula function_formula;
            // Name of the function
            std::string function_name = "";
            // Number of the function
            int function_number = 0;
            // Type of the studied function
            Studied_Type type = Studied_Type::ST_Sequence;
        };

        // Returns the interval of a positive function
        scls::Interval function_sign(Function_Studied current_function, std::string& redaction);
        // Returns the interval of an increasing function
        scls::Interval function_variation(scls::Formula current_function, std::string& redaction);

        //******************
        //
        // Complex number handling
        //
        //******************

        // Returns the current text to simplify
        inline std::string complex_number_simplify_input() const {if(a_complex_number_simplify_input.get() == 0) return std::string(); return a_complex_number_simplify_input.get()->text();};

        //******************
        //
        // Sequences handling
        //
        //******************

        // Adds a recursion to the sequence
        void sequences_add_recursion();
        // Convert a string to a polymonial with sequences datas
        scls::Formula sequences_string_to_polymonial();
        // Unload the recursions in the sequences
        inline void unload_sequences(){a_sequences_analyse_recursions_indices.clear();a_sequences_analyse_recursions_titles.clear();a_sequences_analyse_recursions_values.clear();};

        // Returns the current text to analyse
        inline std::string sequences_analyse_input() const {if(a_sequences_analyse_input.get() == 0) return std::string(); return a_sequences_analyse_input.get()->text();};
        // Update the title of the sequences
        inline void update_sequences_title() {if(a_sequences_analyse_recursions_titles.size() <= 0) {a_sequences_analyse_input_start.get()->set_text("s(n) = ");} else {a_sequences_analyse_input_start.get()->set_text("s(n + " + std::to_string(a_sequences_analyse_recursions_titles.size()) + ") = ");}};

        //******************
        //
        // Check the events
        //
        //******************

        // Check the complex number event
        void check_complex_number_events();
        // Check the functions event
        void check_function_events();
        // Check the navigation event
        void check_navigation_events();
        // Check the sequences event
        void check_sequences_events();
        // Update the events
        void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the complex number page
        void display_complex_number_page();
        // Displays the function page
        void display_function_page();
        // Displays the home page
        void display_home_page();
        // Displays the number theory page
        void display_number_theory_page();
        // Displays the sequences page
        void display_sequences_page();
        // Hides all the pages
        void hide_all();

        // Returns / resets the current page
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_ALGEBRIC_SOLVER_HOME_PAGE;
        } a_current_state;

        //******************
        //
        // GUI stuff
        //
        //******************

        // Navigation button
        std::shared_ptr<scls::GUI_Text> a_complex_number_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_function_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_home_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_number_theory_button;
        std::shared_ptr<scls::GUI_Text> a_sequences_button;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_complex_number_page;
        std::shared_ptr<scls::GUI_Object> a_function_page;
        std::shared_ptr<scls::GUI_Object> a_home_page;
        std::shared_ptr<scls::GUI_Object> a_number_theory_page;
        std::shared_ptr<scls::GUI_Object> a_sequences_page;

        // Complex number page
        // Simplification part
        std::shared_ptr<scls::GUI_Text> a_complex_number_simplify_button;
        std::shared_ptr<scls::GUI_Text_Input> a_complex_number_simplify_input;
        std::shared_ptr<scls::GUI_Text> a_complex_number_simplify_result;

        // Sequences page
        std::shared_ptr<scls::GUI_Text> a_sequences_redaction;
        // Analyse part
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_add_recursion_button;
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_button;
        std::shared_ptr<scls::GUI_Text_Input> a_sequences_analyse_input;
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_input_start;
        std::shared_ptr<scls::GUI_Object> a_sequences_analyse_recursions;
        std::vector<std::shared_ptr<scls::GUI_Text_Input>> a_sequences_analyse_recursions_indices;
        std::vector<std::shared_ptr<scls::GUI_Text>> a_sequences_analyse_recursions_titles;
        std::vector<std::shared_ptr<scls::GUI_Text_Input>> a_sequences_analyse_recursions_values;
    };

    class __Temp_Pleos_Window : public scls::Window {
        // Temporary used window by PLEOS
    public :
        // __Temp_Pleos_Window constructor
        __Temp_Pleos_Window(unsigned int w, unsigned int h, std::string path) : scls::Window(w, h, path) { set_window_title("PLEOS - Solveur algébrique"); }

        // Create an object in the window
        std::shared_ptr<scls::Object> __create_loaded_object_from_type(std::string object_name, std::string object_type) {
            if(object_name == "algebric_solver") {
                std::shared_ptr<Algebric_Solver_Page> hub = *new_page_2d<Algebric_Solver_Page>(object_name);

                // Return the good object
                std::shared_ptr<scls::Object> to_return = hub;
                return to_return;
            } return scls::Window::__create_loaded_object_from_type(object_name, object_type);
        }
    };
}

#endif // PLEOS_ALGEBRIC_SOLVER
