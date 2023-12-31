/*
 * File: program.h
 * ---------------
 * This interface exports a Program class for storing a BASIC
 * program.
 */

#ifndef _program_h
#define _program_h

#include <set>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * This class stores the lines in a BASIC program.  Each line
 * in the program is stored in order according to its line number.
 * Moreover, each line in the program is associated with two
 * components:
 *
 * 1. The source line, which is the complete line (including the
 *    line number) that was entered by the user.
 *
 * 2. The parsed representation of that statement, which is a
 *    pointer to a Statement.
 */

class Program {

public:
  /*
   * Constructor: Program
   * Usage: Program program;
   * -----------------------
   * Constructs an empty BASIC program.
   */

  Program();

  /*
   * Destructor: ~Program
   * Usage: usually implicit
   * -----------------------
   * Frees any heap storage associated with the program.
   */

  ~Program();

  /*
   * Method: clear
   * Usage: program.clear();
   * -----------------------
   * Removes all lines from the program.
   */

  void clear();

  /*
   * Method: addSourceLine
   * Usage: program.addSourceLine(lineNumber, line);
   * -----------------------------------------------
   * Adds a source line to the program with the specified line number.
   * If that line already exists, the text of the line replaces
   * the text of any existing line and the parsed representation
   * (if any) is deleted.  If the line is new, it is added to the
   * program in the correct sequence.
   */

  void addSourceLine(int lineNumber, const std::string &line);

  /*
   * Method: removeSourceLine
   * Usage: program.removeSourceLine(lineNumber);
   * --------------------------------------------
   * Removes the line with the specified number from the program,
   * freeing the memory associated with any parsed representation.
   * If no such line exists, this method simply returns without
   * performing any action.
   */

  void removeSourceLine(int lineNumber);

  /*
   * Method: getSourceLine
   * Usage: string line = program.getSourceLine(lineNumber);
   * -------------------------------------------------------
   * Returns the program line with the specified line number.
   * If no such line exists, this method returns the empty string.
   */

  std::string getSourceLine(int lineNumber);

  /*
   * Method: getFirstLineNumber
   * Usage: int lineNumber = program.getFirstLineNumber();
   * -----------------------------------------------------
   * Returns the line number of the first line in the program.
   * If the program has no lines, this method returns -1.
   */

  std::vector<int> getLISTLineNumber();

  /*
   * Method: getNextLineNumber
   * Usage: int nextLine = program.getNextLineNumber(lineNumber);
   * ------------------------------------------------------------
   * Returns the line number of the first line in the program whose
   * number is larger than the specified one, which must already exist
   * in the program.  If no more lines remain, this method returns -1.
   */

  // 获取下一行号
  int getNextLineNumber(int lineNumber);

  // 获取最低行号
  int getLowestNumber();

  // 添加GOTO操作
  void addGOTOoperation(int lineNumber, int nextLineNumber);

  // 添加IF操作
  void addIFoperation(int lineNumber, int nextLineNumber);

  // 清除IF操作
  void IFclear();

private:
  int min_index = -1;                      // min_lineNum's index
  std::vector<int> index;                  // chronological index in line
  std::unordered_map<int, std::string> pg; // lineNumber->string
  std::unordered_map<int, int> go;         // from numfirst to numnext
  std::unordered_map<int, int> opif;       // from numfirst to numnext
};

#endif
