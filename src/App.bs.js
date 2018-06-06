// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var RepoItem$ReactTemplate = require("./RepoItem.bs.js");

var component = ReasonReact.reducerComponent("App");

function str(prim) {
  return prim;
}

var dummyRepo = /* record */[
  /* full_name */"jsdf/reason-react-hacker-news",
  /* stargazers_count */27,
  /* html_url */"https://github.com/jsdf/reason-react-hacker-news"
];

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var repoData = param[/* state */1][/* repoData */0];
              var loadReposButton = React.createElement("button", {
                    onClick: (function () {
                        return Curry._1(send, /* Loaded */[dummyRepo]);
                      })
                  }, "Load Repos");
              var repoItem = repoData ? ReasonReact.element(/* None */0, /* None */0, RepoItem$ReactTemplate.make(repoData[0], /* array */[])) : loadReposButton;
              return React.createElement("div", {
                          className: "App"
                        }, React.createElement("h1", undefined, "Reason Projects"), repoItem);
            }),
          /* initialState */(function () {
              return /* record */[/* repoData : None */0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [/* record */[/* repoData : Some */[action[0]]]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.str = str;
exports.dummyRepo = dummyRepo;
exports.make = make;
/* component Not a pure module */
