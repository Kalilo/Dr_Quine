//import UIKit
import Foundation
import Darwin

/*
 this is a comment
 */

class Quine {
    let data = ["//import UIKit\nimport Foundation\nimport Darwin\n\n/*\n this",
                " is a comment\n */\n\nclass Quine {\n    let data = [",
                "]\n    let filename = \"Grace_kid.swift\"\n\n    func esc_cha",
                "r(c: Character) -> String {\n        if ([\"\\n\", \"\\\\\", ",
                "\"\\t\", \"\\\"\"].contains(c)) {\n            let s: String ",
                "= String(c)\n            if (s == \"\\n\") {\n               ",
                " return (\"\\\\n\")\n            }\n            if (s == \"\\",
                "\\\") {\n                return (\"\\\\\\\\\")\n            }",
                "\n            if (s == \"\\\"\") {\n                return (",
                "\"\\\\\\\"\")\n            }\n            if (s == \"\\t\") {",
                "\n                return (\"\\\\t\")\n            }\n        ",
                "}\n        return (String(c))\n    }\n\n    func write(str: S",
                "tring) {\n        do {\n            try str.write(toFile: fil",
                "ename, atomically: false, encoding: String.Encoding.utf8)\n  ",
                "      }\n        catch let error as NSError {\n            pr",
                "int(\"Error Writing to File: \\(error)\")\n            exit(0",
                ")\n        }\n    }\n\n    func main() {\n        var content",
                ": String = \"\"\n\n        for k in 0...1 {\n            cont",
                "ent += data[k]\n        }\n        content += \"\\\"\"\n     ",
                "   for k in 0...25 {\n            for l in data[k].characters",
                ".indices {\n                content += esc_char(c: data[k][l]",
                ")\n            }\n            content += \"\\\",\\n          ",
                "      \\\"\"\n        }\n        content += \"\\\"\"\n       ",
                " for k in 2...25 {\n            content += data[k]\n        }",
                "\n        self.write(str: content)\n    }\n}\n\nlet q = Quine",
                ".init()\n\nq.main()\n",
                ""]
    let filename = "Grace_kid.swift"
    
    func esc_char(c: Character) -> String {
        if (["\n", "\\", "\t", "\""].contains(c)) {
            let s: String = String(c)
            if (s == "\n") {
                return ("\\n")
            }
            if (s == "\\") {
                return ("\\\\")
            }
            if (s == "\"") {
                return ("\\\"")
            }
            if (s == "\t") {
                return ("\\t")
            }
        }
        return (String(c))
    }
    
    func write(str: String) {
        do {
            try str.write(toFile: filename, atomically: false, encoding: String.Encoding.utf8)
        }
        catch let error as NSError {
            print("Error Writing to File: \(error)")
            exit(0)
        }
    }
    
    func main() {
        var content: String = ""
        
        for k in 0...1 {
            content += data[k]
        }
        content += "\""
        for k in 0...25 {
            for l in data[k].characters.indices {
                content += esc_char(c: data[k][l])
            }
            content += "\",\n                \""
        }
        content += "\""
        for k in 2...25 {
            content += data[k]
        }
        self.write(str: content)
    }
}

let q = Quine.init()

q.main()
