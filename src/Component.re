/* State declaration */
type state = {
  count: int,
  show: bool,
  modal:bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle
  | Open;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");
let transition= <MaterialUi.Slide direction=`Up/>;
/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {count: 0, show: false, modal: false},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    | Open => ReasonReact.Update({...state, modal: ! state.modal})
    },

  render: self => {
    <div>
    <MaterialUi.AppBar position=`Sticky>
      <MaterialUi.Toolbar>
        <MaterialUi.IconButton
          color=`Inherit
          onClick= {_event => self.send(Toggle)}
        > 
          <MscharleyBsMaterialUiIcons.Menu.Filled/>
        </MaterialUi.IconButton>
        <MaterialUi.Typography variant=`H6 color=`Inherit noWrap=true>
          "Khufu Recruiment platform"
        </MaterialUi.Typography>
        <div className="grow" />
          <div className="search">
            <div className="searchIcon">
              <MscharleyBsMaterialUiIcons.Search.Filled />
            </div>
            <MaterialUi.InputBase
              placeholder="Search..."
              classes=[
              Root("inputRoot"),
              Input("inputInput"),
            ]
            />
          </div>
      </MaterialUi.Toolbar>
    </MaterialUi.AppBar>
    <nav>
      <MaterialUi.Drawer
                variant=`Temporary
                open_=self.state.show
                onClose= {_event => self.send(Toggle)}
              >
          <MaterialUi.Divider/>
          <MaterialUi.List>
            <MaterialUi.ListItem button=true >
              <MaterialUi.ListItemIcon>
                <MscharleyBsMaterialUiIcons.PersonPin.Filled/>
              </MaterialUi.ListItemIcon>
              <MaterialUi.ListItemText primary= ReasonReact.string("Profile") />
            </MaterialUi.ListItem>
          </MaterialUi.List>
          <MaterialUi.Divider/>
          <MaterialUi.List>
            <MaterialUi.ListItem button=true>
              <MaterialUi.ListItemIcon> 
                <MscharleyBsMaterialUiIcons.Dashboard.Filled/>
              </MaterialUi.ListItemIcon>
              <MaterialUi.ListItemText primary=ReasonReact.string("Dashboard") />
            </MaterialUi.ListItem>
            <MaterialUi.ListItem button=true>
              <MaterialUi.ListItemIcon> 
                <MscharleyBsMaterialUiIcons.TurnedIn.Filled/>
              </MaterialUi.ListItemIcon>
              <MaterialUi.ListItemText primary=ReasonReact.string("Tickets") />
            </MaterialUi.ListItem>
            <MaterialUi.ListItem button=true>
              <MaterialUi.ListItemIcon> 
                <MscharleyBsMaterialUiIcons.People.Filled/>
              </MaterialUi.ListItemIcon>
              <MaterialUi.ListItemText primary=ReasonReact.string("Candidates") />
            </MaterialUi.ListItem>
          </MaterialUi.List>
      </MaterialUi.Drawer>
    </nav>

    <MaterialUi.Button
      color=`Primary
      variant=`Contained
      >
      "Example Button"
    </MaterialUi.Button>

    <MaterialUi.Button variant=`Outlined color=`Primary onClick={_event => self.send(Open)}>
          "Slide in alert dialog"
        </MaterialUi.Button>
        <MaterialUi.Dialog
          open_=self.state.modal
          keepMounted=true
          onClose={_event => (value)=> self.send(Open)}
        >
          <MaterialUi.DialogTitle>
            "Use Google's location service?"
          </MaterialUi.DialogTitle>
          <MaterialUi.DialogContent>
            <MaterialUi.DialogContentText>
              "Let Google help apps determine location. This means sending anonymous location data to
              Google, even when no apps are running."
            </MaterialUi.DialogContentText>
          </MaterialUi.DialogContent>
          <MaterialUi.DialogActions>
            <MaterialUi.Button onClick={_event => self.send(Open)} color=`Primary>
              "Disagree"
            </MaterialUi.Button>
            <MaterialUi.Button onClick={_event => self.send(Open)} color=`Primary>
              "Agree"
            </MaterialUi.Button>
          </MaterialUi.DialogActions>
        </MaterialUi.Dialog>
  </div>;
  },
};
