//import UIKit
import Foundation

/*
 this is a comment
 */

class Quine {
    let data = ["//import UIKit\n\n/*\n this is a comment\n */\n\nclass Quine ",
                "{\n    let data = [",
                "]\n\n    func esc_char(c: Character) -> String {\n        if ",
                "([\"\\n\", \"\\\\\", \"\\t\", \"\\\"\"].contains(c)) {\n     ",
                "       let s: String = String(c)\n            if (s == \"\\n",
                "\") {\n                return (\"\\\\n\")\n            }\n   ",
                "         if (s == \"\\\\\") {\n                return (\"\\\\",
                "\\\\\")\n            }\n            if (s == \"\\\"\") {\n   ",
                "             return (\"\\\\\\\"\")\n            }\n          ",
                "  if (s == \"\\t\") {\n                return (\"\\\\t\")\n  ",
                "          }\n        }\n        return (String(c))\n    }\n\n",
                "    func main() {\n        /*\n         this is a comment in ",
                "the main\n         */\n        for k in 0...1 {\n            ",
                "print(data[k], terminator: \"\")\n        }\n        print(\"",
                "\\\"\", terminator: \"\")\n        for k in 0...21 {\n       ",
                "     for l in data[k].characters.indices {\n                p",
                "rint(esc_char(c: data[k][l]), terminator: \"\")\n            ",
                "}\n            print(\"\\\",\\n                \\\"\", termin",
                "ator: \"\")\n        }\n        print(\"\\\"\", terminator: ",
                "\"\")\n        for k in 2...21 {\n            print(data[k], ",
                "terminator: \"\")\n        }\n    }\n}\n\nlet q = Quine.init(",
                ")\n\nq.main()",
                ""]
    
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
    
    func main() {
        /*
         this is a comment in the main
         */
        for k in 0...1 {
            print(data[k], terminator: "")
        }
        print("\"", terminator: "")
        for k in 0...21 {
            for l in data[k].characters.indices {
                print(esc_char(c: data[k][l]), terminator: "")
            }
            print("\",\n                \"", terminator: "")
        }
        print("\"", terminator: "")
        for k in 2...21 {
            print(data[k], terminator: "")
        }
    }
}

let q = Quine.init()

//q.main()

//let file = open("tmp.txt")

//"str".write(to:atomically:encoding:)
//let dir = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first

//let dir = FileManager.default
//print(dir.currentDirectoryPath)
//let path = fileManager.currentDirectoryPath

//let file = FileHandle.init(forWritingAtPath: "./made_by_swift.txt")

//file?.write("hello world!".data(using: String.Encoding.utf8)!)

//let documentDirectory = try! FileManager.default.url(for: .documentDirectory, in: .userDomainMask, appropriateFor: nil, create: true)

//let file: FileHandle? = FileHandle(forWritingAtPath: "swift_test.txt")
let file: FileHandle? = FileHandle(forWritingAtPath: "swifttest.txt")

if file == nil {
    print("error opening file.");
    exit
}
else {
    let str = "this is a test string"
    file?.write(str.data(using: .utf8)!)
    file?.closeFile()
}
