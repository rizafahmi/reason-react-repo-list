type state = {repoData: option(array(RepoData.repo))};
type action =
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

let str = ReasonReact.string;

let make = children => {
  ...component,
  initialState: () => {repoData: None},
  didMount: self => {
    let handleReposLoaded = repoData => self.send(Loaded(repoData));

    RepoData.fetchRepos()
    |> Js.Promise.then_(repoData => {
         handleReposLoaded(repoData);
         Js.Promise.resolve();
       })
    |> ignore;
  },
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  render: ({state: {repoData}, send}) => {
    let repoItems =
      switch (repoData) {
      | Some(repos) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo />,
            repos,
          ),
        )
      | None => str("Loading...")
      };
    <div className="App">
      <h1> (str("Reason Projects")) </h1>
      repoItems
    </div>;
  },
};
