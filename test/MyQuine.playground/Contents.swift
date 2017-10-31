//import UIKit

/*
 this is a comment
 */

class Quine {
    let data = ["//import UIKit\n\n/*\n this is a comment\n */\n\nclass Quine ",
                "{\n\tlet data = [",
                "]\n\t\n\tfunc esc_char(c: Character) -> String {\n\t\t\tif ([",
                "\"\\n\", \"\\\\\", \"\\t\", \"\\\"\"].contains(c)) {\n\t\t\t",
                "\t\tlet s: String = String(c)\n\t\t\t\t\tif (s == \"\\n\") {",
                "\n\t\t\t\t\t\t\treturn (\"\\\\n\")\n\t\t\t\t\t}\n\t\t\t\t\tif",
                " (s\t== \"\\\\\") {\n\t\t\t\t\t\t\treturn (\"\\\\\\\\\")\n\t",
                "\t\t\t\t}\n\t\t\t\t\tif (s == \"\\\"\") {\n\t\t\t\t\t\t\tret",
                "urn (\"\\\\\\\"\")\n\t\t\t\t\t}\n\t\t\t\t\tif (s == \"\\t\") ",
                "{\n\t\t\t\t\t\t\treturn (\"\\\\n\")\n\t\t\t\t\t}\n\t\t\t}\n\t",
                "\t\treturn (String(c))\n\t}\n\t\n\tfunc main() {\n\t\t\t/*\n",
                "\t\t\t\t\tthis is a comment in the main\n\t\t\t*/\n\t\t\tfor ",
                "k in 0...1 {\n\t\t\t\t\tprint(data[k])\n\t\t\t}\n\t\t\tprint(",
                "\"\\\"\", terminator: \"\")\n\t\t\tfor k in 0...3 {\n\t\t\t\t",
                "\tfor l in data[k].characters.indices {\n\t\t\t\t\t\t\tprint(e",
                "sc_char(c: data[k][l]), terminator: \"\")\n\t\t\t\t\t}\n\t\t\t",
                "\t\tprint(\"\\\",\\n\\t\\t\\t\\t\\t\\t\\t\\t\\\"\", terminator",
                ": \"\")\n\t\t\t}\n\t\t\tprint(\"\\\"\", terminator: \"\")\n\t",
                "\t\tfor k in 2...3 {\n\t\t\t\t\tprint(data[k])\n\t\t\t}\n\t}",
                "\n}\n\nlet q = Quine.init()\n\nq.main()"]
    
    func esc_char(c: Character) -> String {
        if (["\n", "\\", "\t", "\""].contains(c)) {
            let s: String = String(c)
            if (s == "\n") {
                return ("\\n")
            }
            if (s  == "\\") {
                return ("\\\\")
            }
            if (s == "\"") {
                return ("\\\"")
            }
            if (s == "\t") {
                return ("\\n")
            }
        }
        return (String(c))
    }
    
    func main() {
        /*
            this is a comment in the main
        */
        for k in 0...1 {
            print(data[k])
        }
        print("\"", terminator: "")
        for k in 0...3 {
            for l in data[k].characters.indices {
                print(esc_char(c: data[k][l]), terminator: "")
            }
            print("\",\n                \"", terminator: "")
        }
        print("\"", terminator: "")
        for k in 2...3 {
            print(data[k])
        }
    }
}

let q = Quine.init()

q.main()