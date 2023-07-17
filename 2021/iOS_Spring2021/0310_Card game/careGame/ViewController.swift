//
//  ViewController.swift
//  careGame
//
//  Created by Vesper Lee on 2021/3/10.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var cardButtons: [UIButton]!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    var emojis = ["👻","🎃"]
    
    @IBAction func touchCard(_ sender: UIButton) {
        if let cardIndex = cardButtons.firstIndex(of: sender){
            let emoji = emojis[cardIndex]
            if sender.currentTitle == emoji{
                sender.setTitle("", for: UIControl.State.normal)
                sender.backgroundColor = #colorLiteral(red: 0.9607843161, green: 0.7058823705, blue: 0.200000003, alpha: 1)
                print ("Click")
            }
            else{
                sender.setTitle(emoji, for: UIControl.State.normal)
                sender.backgroundColor = #colorLiteral(red: 1, green: 1, blue: 1, alpha: 1)
            }
        }else{
            
        }

    }
    
}

