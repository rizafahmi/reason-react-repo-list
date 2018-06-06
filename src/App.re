let component = ReasonReact.reducerComponent("App");

let str = ReasonReact.stringToElement;
let dummyRepo: RepoData.repo = {
  stargazers_count: 27,
  full_name: "jsdf/reason-react-hacker-news",
  html_url: "https://github.com/jsdf/reason-react-hacker-news",
};

let make = _children => {
  ...component,
  initialState: () => {repoData: dummyRepo},
  render: _self =>
    <div className="App">
      <h1> (str("Reason Projects")) </h1>
      <RepoItem repo=dummyRepo />
    </div>,
};
