const C = require("./database/c");
const PF = require("./database/pf");
const SF = require("./database/sf");
const PG = require("./database/pg");
const SG = require("./database/sg");

const player = require("./player");

let metrics = [];

function compare() {
  let playerADV = player.adv.find(item => item.Season === "Career");
  let playerPer36 = player.per36.find(item => item.Season === "Career");
  let playerShot = player.shot.find(item => item.Season === "Career");

  for (let item of C) {
    let acc = 0.0;

    let advCareer = item.adv.find(i => i.Season === "Career");
    let shotCareer = item.shot.find(h => h.Season === "Career");
    let per36Career = item.per36.find(u => u.Season === "Career");

    acc += Math.pow(playerADV["3PAr"] - advCareer["3PAr"], 2);
    acc += Math.pow(playerADV.FTr - advCareer.FTr, 2);
    acc += Math.pow(playerADV["ORB%"] - advCareer["ORB%"], 2);
    acc += Math.pow(playerADV["DRB%"] - advCareer["DRB%"], 2);
    acc += Math.pow(playerADV["TRB%"] - advCareer["TRB%"], 2);
    acc += Math.pow(playerADV["AST%"] - advCareer["AST%"], 2);
    acc += Math.pow(playerADV["STL%"] - advCareer["STL%"], 2);
    acc += Math.pow(playerADV["BLK%"] - advCareer["BLK%"], 2);

    acc += Math.pow(playerShot["Dist."] / 20 - shotCareer["Dist."] / 20, 2);
    acc += Math.pow(playerShot["2P"] - shotCareer["2P"], 2);
    acc += Math.pow(playerShot["0-3"] - shotCareer["0-3"], 2);
    acc += Math.pow(playerShot["3-10"] - shotCareer["3-10"], 2);
    acc += Math.pow(playerShot["10-16"] - shotCareer["10-16"], 2);
    acc += Math.pow(playerShot["16-3pt"] - shotCareer["16-3pt"], 2);
    acc += Math.pow(playerShot["3P"] - shotCareer["3P"], 2);
    acc += Math.pow(playerShot["%FGA"] - shotCareer["%FGA"], 2);

    acc += Math.pow(playerPer36["3PA"] / 10 - per36Career["3PA"] / 10, 2);
    acc += Math.pow(playerPer36["2PA"] / 20 - per36Career["2PA"] / 20, 2);

    acc = Math.sqrt(acc);

    metrics.push({ pos: "C", acc });
  }

  for (let item of PF) {
    let acc = 0.0;

    let advCareer = item.adv.find(i => i.Season === "Career");
    let shotCareer = item.shot.find(h => h.Season === "Career");
    let per36Career = item.per36.find(u => u.Season === "Career");

    acc += Math.pow(playerADV["3PAr"] - advCareer["3PAr"], 2);
    acc += Math.pow(playerADV.FTr - advCareer.FTr, 2);
    acc += Math.pow(playerADV["ORB%"] - advCareer["ORB%"], 2);
    acc += Math.pow(playerADV["DRB%"] - advCareer["DRB%"], 2);
    acc += Math.pow(playerADV["TRB%"] - advCareer["TRB%"], 2);
    acc += Math.pow(playerADV["AST%"] - advCareer["AST%"], 2);
    acc += Math.pow(playerADV["STL%"] - advCareer["STL%"], 2);
    acc += Math.pow(playerADV["BLK%"] - advCareer["BLK%"], 2);

    acc += Math.pow(playerShot["Dist."] / 20 - shotCareer["Dist."] / 20, 2);
    acc += Math.pow(playerShot["2P"] - shotCareer["2P"], 2);
    acc += Math.pow(playerShot["0-3"] - shotCareer["0-3"], 2);
    acc += Math.pow(playerShot["3-10"] - shotCareer["3-10"], 2);
    acc += Math.pow(playerShot["10-16"] - shotCareer["10-16"], 2);
    acc += Math.pow(playerShot["16-3pt"] - shotCareer["16-3pt"], 2);
    acc += Math.pow(playerShot["3P"] - shotCareer["3P"], 2);
    acc += Math.pow(playerShot["%FGA"] - shotCareer["%FGA"], 2);

    acc += Math.pow(playerPer36["3PA"] / 10 - per36Career["3PA"] / 10, 2);
    acc += Math.pow(playerPer36["2PA"] / 20 - per36Career["2PA"] / 20, 2);

    acc = Math.sqrt(acc);

    metrics.push({ pos: "PF", acc });
  }

  for (let item of SF) {
    let acc = 0.0;

    let advCareer = item.adv.find(i => i.Season === "Career");
    let shotCareer = item.shot.find(h => h.Season === "Career");
    let per36Career = item.per36.find(u => u.Season === "Career");

    acc += Math.pow(playerADV["3PAr"] - advCareer["3PAr"], 2);
    acc += Math.pow(playerADV.FTr - advCareer.FTr, 2);
    acc += Math.pow(playerADV["ORB%"] - advCareer["ORB%"], 2);
    acc += Math.pow(playerADV["DRB%"] - advCareer["DRB%"], 2);
    acc += Math.pow(playerADV["TRB%"] - advCareer["TRB%"], 2);
    acc += Math.pow(playerADV["AST%"] - advCareer["AST%"], 2);
    acc += Math.pow(playerADV["STL%"] - advCareer["STL%"], 2);
    acc += Math.pow(playerADV["BLK%"] - advCareer["BLK%"], 2);

    acc += Math.pow(playerShot["Dist."] / 20 - shotCareer["Dist."] / 20, 2);
    acc += Math.pow(playerShot["2P"] - shotCareer["2P"], 2);
    acc += Math.pow(playerShot["0-3"] - shotCareer["0-3"], 2);
    acc += Math.pow(playerShot["3-10"] - shotCareer["3-10"], 2);
    acc += Math.pow(playerShot["10-16"] - shotCareer["10-16"], 2);
    acc += Math.pow(playerShot["16-3pt"] - shotCareer["16-3pt"], 2);
    acc += Math.pow(playerShot["3P"] - shotCareer["3P"], 2);
    acc += Math.pow(playerShot["%FGA"] - shotCareer["%FGA"], 2);

    acc += Math.pow(playerPer36["3PA"] / 10 - per36Career["3PA"] / 10, 2);
    acc += Math.pow(playerPer36["2PA"] / 20 - per36Career["2PA"] / 20, 2);

    acc = Math.sqrt(acc);

    metrics.push({ pos: "SF", acc });
  }

  for (let item of PG) {
    let acc = 0.0;

    let advCareer = item.adv.find(i => i.Season === "Career");
    let shotCareer = item.shot.find(h => h.Season === "Career");
    let per36Career = item.per36.find(u => u.Season === "Career");

    acc += Math.pow(playerADV["3PAr"] - advCareer["3PAr"], 2);
    acc += Math.pow(playerADV.FTr - advCareer.FTr, 2);
    acc += Math.pow(playerADV["ORB%"] - advCareer["ORB%"], 2);
    acc += Math.pow(playerADV["DRB%"] - advCareer["DRB%"], 2);
    acc += Math.pow(playerADV["TRB%"] - advCareer["TRB%"], 2);
    acc += Math.pow(playerADV["AST%"] - advCareer["AST%"], 2);
    acc += Math.pow(playerADV["STL%"] - advCareer["STL%"], 2);
    acc += Math.pow(playerADV["BLK%"] - advCareer["BLK%"], 2);

    acc += Math.pow(playerShot["Dist."] / 20 - shotCareer["Dist."] / 20, 2);
    acc += Math.pow(playerShot["2P"] - shotCareer["2P"], 2);
    acc += Math.pow(playerShot["0-3"] - shotCareer["0-3"], 2);
    acc += Math.pow(playerShot["3-10"] - shotCareer["3-10"], 2);
    acc += Math.pow(playerShot["10-16"] - shotCareer["10-16"], 2);
    acc += Math.pow(playerShot["16-3pt"] - shotCareer["16-3pt"], 2);
    acc += Math.pow(playerShot["3P"] - shotCareer["3P"], 2);
    acc += Math.pow(playerShot["%FGA"] - shotCareer["%FGA"], 2);

    acc += Math.pow(playerPer36["3PA"] / 10 - per36Career["3PA"] / 10, 2);
    acc += Math.pow(playerPer36["2PA"] / 20 - per36Career["2PA"] / 20, 2);

    acc = Math.sqrt(acc);

    metrics.push({ pos: "PG", acc });
  }

  for (let item of SG) {
    let acc = 0.0;

    let advCareer = item.adv.find(i => i.Season === "Career");
    let shotCareer = item.shot.find(h => h.Season === "Career");
    let per36Career = item.per36.find(u => u.Season === "Career");

    acc += Math.pow(playerADV["3PAr"] - advCareer["3PAr"], 2);
    acc += Math.pow(playerADV.FTr - advCareer.FTr, 2);
    acc += Math.pow(playerADV["ORB%"] - advCareer["ORB%"], 2);
    acc += Math.pow(playerADV["DRB%"] - advCareer["DRB%"], 2);
    acc += Math.pow(playerADV["TRB%"] - advCareer["TRB%"], 2);
    acc += Math.pow(playerADV["AST%"] - advCareer["AST%"], 2);
    acc += Math.pow(playerADV["STL%"] - advCareer["STL%"], 2);
    acc += Math.pow(playerADV["BLK%"] - advCareer["BLK%"], 2);

    acc += Math.pow(playerShot["Dist."] / 20 - shotCareer["Dist."] / 20, 2);
    acc += Math.pow(playerShot["2P"] - shotCareer["2P"], 2);
    acc += Math.pow(playerShot["0-3"] - shotCareer["0-3"], 2);
    acc += Math.pow(playerShot["3-10"] - shotCareer["3-10"], 2);
    acc += Math.pow(playerShot["10-16"] - shotCareer["10-16"], 2);
    acc += Math.pow(playerShot["16-3pt"] - shotCareer["16-3pt"], 2);
    acc += Math.pow(playerShot["3P"] - shotCareer["3P"], 2);
    acc += Math.pow(playerShot["%FGA"] - shotCareer["%FGA"], 2);

    acc += Math.pow(playerPer36["3PA"] / 10 - per36Career["3PA"] / 10, 2);
    acc += Math.pow(playerPer36["2PA"] / 20 - per36Career["2PA"] / 20, 2);

    acc = Math.sqrt(acc);

    metrics.push({ pos: "SG", acc });
  }

  for (let i = 0; i < metrics.length; i++) {
    for (let j = 0; j < metrics.length; j++) {
      if (metrics[j].acc > metrics[i].acc) {
        let aux = JSON.parse(JSON.stringify(metrics[j]));
        metrics[j] = JSON.parse(JSON.stringify(metrics[i]));
        metrics[i] = aux;
      }
    }
  }

  console.log(metrics);
}

compare();

console.log("ok");
