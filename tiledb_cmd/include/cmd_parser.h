/**
 * @file   cmd_parser.h
 * @author Stavros Papadopoulos <stavrosp@csail.mit.edu>
 *
 * @section LICENSE
 *
 * The MIT License
 *
 * @copyright Copyright (c) 2014 Stavros Papadopoulos <stavrosp@csail.mit.edu>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * @section DESCRIPTION
 *
 * This file defines class CmdParser.
 */

#ifndef CMD_PARSER_H
#define CMD_PARSER_H

#include "command_line.h"
#include "array_schema.h"
#include <inttypes.h>

/** 
 * Indicates which arguments are used from the command line for query
 * 'clear_array'. 
 */
#define PS_CLEAR_ARRAY_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'define_array'. 
 */
#define PS_DEFINE_ARRAY_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                                CL_ATTRIBUTE_NAMES_BITMAP |\
                                CL_DIM_NAMES_BITMAP |\
                                CL_DIM_DOMAINS_BITMAP | CL_TYPES_BITMAP |\
                                CL_CELL_ORDER_BITMAP | CL_CAPACITY_BITMAP |\
                                CL_TILE_EXTENTS_BITMAP | CL_TILE_ORDER_BITMAP |\
                                CL_CONSOLIDATION_STEP_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'delete_array'. 
 */
#define PS_DELETE_ARRAY_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'export_to_CSV'. 
 */
#define PS_EXPORT_TO_CSV_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                                 CL_ATTRIBUTE_NAMES_BITMAP |\
                                 CL_DIM_NAMES_BITMAP | CL_MODE_BITMAP |\
                                 CL_FILENAME_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'filter'. 
 */
#define PS_FILTER_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                          CL_EXPRESSION_BITMAP | CL_RESULT_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'join'. 
 */
#define PS_JOIN_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                        CL_RESULT_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'load_csv'. 
 */
#define PS_LOAD_CSV_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                            CL_FILENAME_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'load_csv'. 
 */
#define PS_LOAD_SORTED_BIN_BITMAP (CL_WORKSPACE_BITMAP |\
                                   CL_ARRAY_NAMES_BITMAP | CL_FILENAME_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'nearest_neighbors'. 
 */
#define PS_NN_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                      CL_COORDINATES_BITMAP | CL_NUMBERS_BITMAP  |\
                      CL_RESULT_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'retile'. 
 */
#define PS_RETILE_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                          CL_CELL_ORDER_BITMAP | CL_CAPACITY_BITMAP  |\
                          CL_TILE_EXTENTS_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'show_array_schema'. 
 */
#define PS_SHOW_ARRAY_SCHEMA_BITMAP (CL_WORKSPACE_BITMAP |\
                                     CL_ARRAY_NAMES_BITMAP)

/** 
 * Indicates which arguments are used from the command line for query
 * 'subarray'. 
 */
#define PS_SUBARRAY_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                            CL_ATTRIBUTE_NAMES_BITMAP |\
                            CL_RANGE_BITMAP | CL_RESULT_BITMAP |\
                            CL_MODE_BITMAP)
/** 
 * Indicates which arguments are used from the command line for query
 * 'update_csv'. 
 */
#define PS_UPDATE_BITMAP (CL_WORKSPACE_BITMAP | CL_ARRAY_NAMES_BITMAP |\
                          CL_FILENAME_BITMAP)

/** Objects of this class properly parse command lines. */
class CmdParser {
 public:
  // CONSTRUCTORS
  /** Empty constructor. */
  CmdParser() {}

  // PARSING METHODS
  /** Parse command line for query 'clear_array'. */
  void parse_clear_array(const CommandLine& cl) const;
  /** Parse command line for query 'define_array' and return the schema. */
  const ArraySchema* parse_define_array(const CommandLine& cl) const;
  /** Parse command line for query 'delete_array'. */
  void parse_delete_array(const CommandLine& cl) const;
  /** 
   * Parse command line for query 'export_to_csv'. Returns (by reference
   * the ids of the dimensions and attributes the export will focus on.
   */
  void parse_export_to_csv(const CommandLine& cl,
                           std::vector<std::string>& dim_names,
                           std::vector<std::string>& attribute_names,
                           bool& reverse) const;
  /** Parse command line for query 'load_csv'. */
  void parse_load_csv(const CommandLine& cl) const;
  /** Parse command line for query 'load_sorted_bin'. */
  void parse_load_sorted_bin(const CommandLine& cl) const;
  /** Parse command line for query 'show_array_schema'. */
  void parse_show_array_schema(const CommandLine& cl) const;
  /** 
   * Parse command line for query 'subarray'. Returns a multi-dimensional 
   * range, and (by reference) a list of attribute names.
   */
  std::vector<double> parse_subarray(
      const CommandLine& cl,
      std::vector<std::string>& attribute_names,
      bool& reverse) const;
  /** Parse command line for query 'update_csv'. */
  void parse_update_csv(const CommandLine& cl) const;

 private:
  // PRIVATE METHODS
  /** Checks the array names in command line for soundness and returns them. */
  std::vector<std::string> check_array_names(const CommandLine& cl) const;
  /** 
   * Checks the attribute names in command line for soundness and returns
   * them. 
   */
  std::vector<std::string> check_attribute_names(const CommandLine& cl) const;
  /** 
   * Checks the capacity in command line for soundness and returns it. 
   * If no capacity is given in the command line, it returns -1.
   */ 
  int64_t check_capacity(const CommandLine& cl) const;
  /** 
   * Checks the consolidation step in command line for soundness and returns
   * it. 
   */ 
  int check_consolidation_step(const CommandLine& cl) const;
  /** 
   * Checks the dimension domains in command line for soundness and returns
   * them. 
   */ 
  std::vector<std::pair<double, double> > check_dim_domains(
      const CommandLine& cl, int dim_num) const;
  /** 
   * Checks the dimension names in command line for soundness and returns
   * them. 
   */ 
  std::vector<std::string> check_dim_names(
      const CommandLine& cl, 
      const std::vector<std::string>& attribute_names) const;
  /** Checks the cell order in command line for soundness and returns it. */
  ArraySchema::CellOrder check_cell_order(const CommandLine& cl) const;
  /** Checks the tile order in command line for soundness and returns it. */
  ArraySchema::TileOrder check_tile_order(const CommandLine& cl) const;
  /** Checks the tile extents in command line for soundness. */
  std::vector<double> check_tile_extents(
      const CommandLine& cl,
      int dim_num,
      const std::vector<std::pair<double, double> >& dim_domains) const;
  /** 
   * Checks the range in command line for soundness and returns it as 
   * an array of double numbers.
   */
  std::vector<double> check_range(const CommandLine& cl) const;
  /** Returns true if the mode is "reverse" and false if it is "normal". */
  bool check_reverse(const CommandLine& cl) const;
  /** 
   * Checks the types in command line for soundness and returns
   * them. 
   */
  std::pair<std::vector<const std::type_info*>,
            std::vector<int> > 
      check_types(const CommandLine& cl, int attribute_num) const;
  /** Returns the attribute names from the command line. */
  std::vector<std::string> get_attribute_names(const CommandLine& cl) const;
  /** Returns the dimension names from the command line. */
  std::vector<std::string> get_dim_names(const CommandLine& cl) const;
};

#endif