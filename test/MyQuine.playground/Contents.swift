//import UIKit
import Foundation
import Darwin

/*
 this is a comment
 */

class Quine {
    let data = ["//import UIKit\nimport Foundation\nimport Darwin\n\n/*\n this",
                " is a comment\n */\n\nclass Quine {\n    let data = [",
                "]\n    var iterations = ",
                "\n    var filename = \"Sulley_\"\n    \n    func esc_char(_ c",
                ": Character) -> String {\n        if ([\"\\n\", \"\\\\\", \"",
                "\\t\", \"\\\"\"].contains(c)) {\n            let s: String = ",
                "String(c)\n            if (s == \"\\n\") {\n                r",
                "eturn (\"\\\\n\")\n            }\n            if (s == \"\\\\",
                "\") {\n                return (\"\\\\\\\\\")\n            }\n",
                "            if (s == \"\\\"\") {\n                return (\"",
                "\\\\\\\"\")\n            }\n            if (s == \"\\t\") {\n",
                "                return (\"\\\\t\")\n            }\n        }",
                "\n        return (String(c))\n    }\n    \n    func write(str",
                ": String) {\n        do {\n            try str.write(toFile: ",
                "filename, atomically: false, encoding: String.Encoding.utf8)",
                "\n        }\n        catch let error as NSError {\n          ",
                "  print(\"Error Writing to File: \\(error)\")\n            ex",
                "it(0)\n        }\n    }\n    \n    func exec(_ command: [Stri",
                "ng]) {\n        let p = Process.init()\n        p.launchPath ",
                "= \"/usr/bin/env\"\n        p.arguments = command\n        \n",
                "        let pipe = Pipe()\n        p.standardOutput = pipe\n ",
                "       p.launch()\n        p.waitUntilExit()\n    }\n    \n  ",
                "  func printQuine() {\n        var content: String = \"\"\n  ",
                "      \n        for k in 0...1 {\n            content += data",
                "[k]\n        }\n        content += \"\\\"\"\n        for k in",
                " 0...42 {\n            for l in data[k].characters.indices {",
                "\n                content += esc_char(data[k][l])\n          ",
                "  }\n            content += \"\\\",\\n                \\\"\"",
                "\n        }\n        content += \"\\\"\"\n        content += ",
                "data[2]\n        content += String(iterations)\n        for k",
                " in 3...42 {\n            content += data[k]\n        }\n    ",
                "    self.write(str: content)\n    }\n    \n    func main() {",
                "\n        \n        if (ProcessInfo.processInfo.environment[",
                "\"MY_SWIFT_QUINE\"] != nil) {\n            iterations -= 1\n ",
                "       }\n        setenv(\"MY_SWIFT_QUINE\", \"true\", 1)\n  ",
                "      \n        if iterations < 0 {\n            exit(0)\n   ",
                "     }\n        \n        filename += String(iterations) + \"",
                ".swift\"\n        self.printQuine()\n        self.exec([\"swi",
                "ftc\", filename])\n        if iterations < 1 {\n            e",
                "xit(0)\n        }\n        filename = \"./\" + filename.repla",
                "cingOccurrences(of: \".swift\", with: \"\", options: .literal",
                ", range: nil)\n        self.exec([\"\\(filename)\"])\n    }\n",
                "}\n\nlet q = Quine.init()\n\nq.main()",
                ""]
    var iterations = 5
    var filename = "Sulley_"
    
    func esc_char(_ c: Character) -> String {
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
    
    func exec(_ command: [String]) {
        let p = Process.init()
        p.launchPath = "/usr/bin/env"
        p.arguments = command
        
        let pipe = Pipe()
        p.standardOutput = pipe
        p.launch()
        p.waitUntilExit()
    }
    
    func printQuine() {
        var content: String = ""
        
        for k in 0...1 {
            content += data[k]
        }
        content += "\""
        for k in 0...42 {
            for l in data[k].characters.indices {
                content += esc_char(data[k][l])
            }
            content += "\",\n                \""
        }
        content += "\""
        content += data[2]
        content += String(iterations)
        for k in 3...42 {
            content += data[k]
        }
        self.write(str: content)
    }
    
    func main() {
        
        if (ProcessInfo.processInfo.environment["MY_SWIFT_QUINE"] != nil) {
            iterations -= 1
        }
        setenv("MY_SWIFT_QUINE", "true", 1)
        
        if iterations < 0 {
            exit(0)
        }
        
        filename += String(iterations) + ".swift"
        self.printQuine()
        self.exec(["swiftc", filename])
        if iterations < 1 {
            exit(0)
        }
        filename = "./" + filename.replacingOccurrences(of: ".swift", with: "", options: .literal, range: nil)
        self.exec(["\(filename)"])
    }
}

let q = Quine.init()

q.main()