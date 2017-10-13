//
//  ViewController.swift
//  WeatherStationApp
//
//  Created by programming-xcode on 10/12/17.
//  Copyright © 2017 programming-xcode. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var webView: UIWebView!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @IBAction func reloadWebView(_ sender: Any) {
        let url = URL(string: "http://192.168.1.118/read")
        let urlreq = URLRequest(url: url!)
        webView.loadRequest(urlreq)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

